#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int dp[1001][1001];
string a, b;

string get_seq() {
	string ret;

	int i = n, j = m;
	while(i > 0 && j > 0) {
		if (dp[i][j] == dp[i - 1][j]) {
			i--;
		}
		else if (dp[i][j] == dp[i][j - 1]) {
			j--;
		}
		else {
			ret.push_back(a[i - 1]);
			i--; j--;
		}
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

int LCS() {
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[n][m];
}

void init() {
	cin >> a >> b;
	n = (int)a.size();
	m = (int)b.size();
}

int main(void) {
	fastio;
	init();

	cout << LCS() << '\n';
	cout << get_seq();
}