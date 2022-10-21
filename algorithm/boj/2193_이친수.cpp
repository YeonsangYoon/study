#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
long long dp[91][2];

long long solve() {
	dp[1][1] = 1;
	for (int i = 2; i <= n; i++) {
		dp[i][0] = dp[i - 1][0] + dp[i - 1][1];
		dp[i][1] = dp[i - 1][0];
	}
	return dp[n][0] + dp[n][1];
}

void init() {
	cin >> n;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}