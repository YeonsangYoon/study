#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int dp[101][101][101];

int LCS3(string a, string b, string c) {
	int la = (int)a.size();
	int lb = (int)b.size();
	int lc = (int)c.size();

	memset(dp, 0, sizeof(dp));

	for (int i = 1; i <= la; i++) {
		for (int j = 1; j <= lb; j++) {
			for (int k = 1; k <= lc; k++) {
				if (a[i - 1] == b[j - 1] && a[i - 1] == c[k - 1])
					dp[i][j][k] = dp[i - 1][j - 1][k - 1] + 1;
				else
					dp[i][j][k] = max(dp[i - 1][j][k], max(dp[i][j - 1][k], dp[i][j][k - 1]));
			}
		}
	}
	return dp[la][lb][lc];
}

int main(void) {
	fastio;
	string a, b, c;
	cin >> a >> b >> c;

	cout << LCS3(a, b, c);
}