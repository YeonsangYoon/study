/**********************************************************************
작성일 : 2022-6-04
문제 :
	크기가 n인 배열이 있을 때, 가장 오른쪽 끝으로 이동하기 위한 최소 횟수를 구하라.
	첫 번째 칸에서 이동을 시작하고, 이동할 수 있는 칸의 범위는 해당 칸의 값이다.
풀이 :
	dp와 메모이제이션으로 시간복잡도를 줄였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n*a)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int n;
int maze[1001], cnt[1001];

void solve() {
	cnt[1] = 0;

	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= i + maze[i]; j++) {
			if (j > n) break;
			cnt[j] = min(cnt[j], cnt[i] + 1);
		}
	}
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> maze[i];
		cnt[i] = INF;
	}
}

int main(void) {
	fastio;
	init();
	solve();

	if (cnt[n] == INF)
		cout << -1;
	else
		cout << cnt[n];
}