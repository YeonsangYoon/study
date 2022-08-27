/**********************************************************************
작성일 : 2022-8-27
문제 :
	입력으로 양의 정수 A와 K가 주어지면, 아래 연산을 이용하여 A를 K로 변경하려고 한다.
	정수 A를 변경할 때 사용할 수 있는 연산 종류는 다음과 같다.
		연산 1: 정수 A에 1을 더한다.
		연산 2: 정수 A에 2를 곱한다.
	정수 A를 정수 K로 만들기 위해 필요한 최소 연산 횟수를 출력하자.
풀이 :
	dp와 메모이제이션을 통해 시간복잡도를 개선하였다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 10000000

int a, k;
int dp[1000001];

int solve() {
	for (int i = a + 1; i <= k; i++)
		dp[i] = INF;

	for (int i = a; i <= k; i++) {
		if (i + 1 <= k)
			dp[i + 1] = min(dp[i + 1], dp[i] + 1);
		if (i * 2 <= k)
			dp[i * 2] = min(dp[i * 2], dp[i] + 1);
	}
	return dp[k];
}

void init() {
	cin >> a >> k;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}