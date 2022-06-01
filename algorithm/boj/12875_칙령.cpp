/**********************************************************************
작성일 : 2022-6-01
문제 :
	N명이 살고 있는 왕국에서 각 사람들에게 돈을 분배하고자 한다.
	이때, 왕의 칙령은 친구 관계에 있는 두 사람의 돈의 차이는 d 이하여야한다.
	이러한 칙령을 지키면서 N명에게 분배했을 때, 돈의 차이의 최대값을 구하라.
풀이 :
	돈의 차이는 친구 관계의 최단거리 x d이다. 따라서 모든 쌍에 대한 최단 거리를
	구한다음 최댓값을 구해야한다.
	플로이드 워셜을 통해 최댓값을 구하고 d를 구한다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10000000
using namespace std;

int n, d;
int isFriend[51][51];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				isFriend[i][j] = min(isFriend[i][j], isFriend[i][k] + isFriend[k][j]);
			}
		}
	}
}

void init() {
	cin >> n >> d;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			char c; cin >> c;
			if (i == j)
				isFriend[i][j] = 0;
			else if (c == 'Y')
				isFriend[i][j] = 1;
			else
				isFriend[i][j] = INF;
		}
	}
}

int main(void) {
	fastio;
	init();
	floyd();

	int dist = -1;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist = max(dist, isFriend[i][j]);
		}
	}

	if (dist == INF)
		cout << -1;
	else
		cout << dist * d;
}