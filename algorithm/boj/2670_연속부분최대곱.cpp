/**********************************************************************
작성일 : 2022-8-12
문제 :
	N개의 실수가 있을 때, 한 개 이상의 연속된 수들의 곱이 최대가 되는 부분을 찾아, 
	그 곱을 출력하는 프로그램을 작성하시오.
풀이 :
	dp를 활용한 알고리즘을 사용하였다. 일차원 배열인 dp배열을 선언하고 
	dp[i]는 i번째 실수를 포함한 연속곱 중 가장 큰값을 나타내도록 점화식을 세웠다.
	dp[i] = max(dp[i-1] * num[i], num[i])
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
long double numbers[10001], dp[10001];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> numbers[i];
	}
	dp[1] = numbers[1];
}

int main(void) {
	fastio;
	init();

	long double ans = dp[1];
	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] * numbers[i], numbers[i]);
		ans = max(ans, dp[i]);
	}

	cout << fixed;
	cout.precision(3);
	cout << ans;
}