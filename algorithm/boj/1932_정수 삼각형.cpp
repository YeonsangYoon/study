/**********************************************************************
작성일 : 2022-6-05
문제 :
	크기가 n인 정수 삼각형이 주어진다. 
	맨 위층에서 시작하여 각 수를 선택항 아래층으로 내려올 때, 가장 큰 경로를 구하라.
풀이 :
	dp와 메모이제이션으로 시간복잡도를 줄였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int dp[501][501], iTriangle[501][501];

int solve() {
	dp[1][1] = iTriangle[1][1];
	for (int i = 1; i <= n - 1; i++) {
		for (int j = 1; j <= i; j++) {
			dp[i + 1][j] = max(dp[i + 1][j], dp[i][j] + iTriangle[i + 1][j]);
			dp[i + 1][j + 1] = max(dp[i + 1][j + 1], dp[i][j] + iTriangle[i + 1][j + 1]);
		}
	}

	int ret = 0;
	for (int i = 1; i <= n; i++)
		ret = max(ret, dp[n][i]);
	return ret;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= i; j++) {
			cin >> iTriangle[i][j];
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}