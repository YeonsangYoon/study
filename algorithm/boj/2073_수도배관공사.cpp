/**********************************************************************
작성일 : 2022-3-08
문제 :
	P개의 파이프를 이어서 D길이로 만들고자 할 때 파이프 용량의 최대 값을 구해라
	이어붙인 파이프의 용량은 각 파이프의 용량 중 최소값이다.
풀이 :
	Knapsack 알고리즘을 응용한 문제이다.
	dp를 길이 * 파이프 개수를 표현한 2차원 배열로 선언해야하지만,
	용량 제한 때문에 불가능하다. 
	따라서, 일차원 배열을 2개 선언하여 이전 정보까지 기록하는 것을 통해
	최대한 메모리를 절약하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(d * p)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_DIST 100001
using namespace std;

int dist, cnt;
int before[MAX_DIST];
int dp[MAX_DIST];

void init() {
	cin >> dist >> cnt;
}

int main() {
	fastio;

	init();

	for (int i = 0; i < cnt; i++) {
		int l, c;
		cin >> l >> c;

		for (int j = l; j <= dist; j++) {
			if (j == l) {
				dp[j] = max(dp[j], c);
			}
			else if (before[j - l] > 0) {
				dp[j] = max(dp[j], min(before[j - l], c));
			}
		}
		for (int j = 1; j <= dist; j++) {
			before[j] = dp[j];
		}
	}

	cout << dp[dist];
}