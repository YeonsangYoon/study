#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int l;
vector<int> dp;
string ad;

int solve() {
	int s = 1, len = 0;
	while (s + len < l) {
		if (ad[len] == ad[s + len]) {
			len++;
			dp[s + len - 1] = len;
		}
		else {
			if (len == 0)
				s++;
			else {
				s += len - dp[len - 1];
				len = dp[len - 1];
			}
		}
	}

	return l - dp[l - 1];
}

void init() {
	cin >> l >> ad;
	dp = vector<int>(l, 0);
}

int main(void) {
	fastio;
	init();

	cout << solve();
}