﻿#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 9901

int n;
int dp[100001][3];

void init() {
	cin >> n;
	dp[1][0] = dp[1][1] = dp[1][2] = 1;
}

int main(void) {
	fastio;
	init();

	for (int i = 2; i <= n; i++) {
		dp[i][0] = (dp[i - 1][1] + dp[i - 1][2]) % MOD;
		dp[i][1] = (dp[i - 1][0] + dp[i - 1][2]) % MOD;
		dp[i][2] = (dp[i - 1][0] + dp[i - 1][1] + dp[i - 1][2]) % MOD;
	}

	cout << (dp[n][0] + dp[n][1] + dp[n][2]) % MOD;
}