/**********************************************************************
작성일 : 2022-08-05
작성자 : 윤연상
문제 :
	45656이란 수를 보자.
	이 수는 인접한 모든 자리의 차이가 1이다. 이런 수를 계단 수라고 한다.
	N이 주어질 때, 길이가 N인 계단 수가 총 몇 개 있는지 구해보자. 
	0으로 시작하는 수는 계단수가 아니다.
풀이 :
	나이브하게 구현하면 연산 수가 10^100 정도이다.
	dp와 메모이제이션을 통하여 시간복잡도를 개선하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 1000000000

int n;
int dp[101][10];

int solve() {
	for (int i = 2; i <= n; i++) {
		for (int j = 0; j < 9; j++) {
			dp[i][j + 1] += dp[i - 1][j];
			dp[i][j + 1] %= MOD;
		}
		for (int j = 1; j < 10; j++) {
			dp[i][j - 1] += dp[i - 1][j];
			dp[i][j - 1] %= MOD;
		}
	}

	int ret = 0;
	for (int i = 0; i < 10; i++) {
		ret += dp[n][i];
		ret %= MOD;
	}
	return ret;
}

void init() {
	cin >> n;
	for (int i = 1; i < 10; i++)
		dp[1][i] = 1;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}