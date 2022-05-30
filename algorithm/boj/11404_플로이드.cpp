/**********************************************************************
작성일 : 2022-5-30
문제 :
	n개의 도시가 있고, 한 도시에서 출발하여 다른 도시에 도착하는 m개의 버스가 있다.
	이때, 모든 도시의 쌍에 대한 최단거리를 구하라.
풀이 :
	우선 간선이 단방향으로 주어진다. 
	이를 인접행렬로 구현하고 '플로이드-워셜'을 사용하여 구하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int n, m;
int adjArr[101][101];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adjArr[i][j] = min(adjArr[i][j], adjArr[i][k] + adjArr[k][j]);
			}
		}
	}
}

void init() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++)
		for (int j = 1; j <= n; j++)
			adjArr[i][j] = (i == j) ? 0 : INF;

	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adjArr[u][v] = min(adjArr[u][v], cost);
	}
}

int main(void) {
	fastio;
	init();
	floyd();

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (adjArr[i][j] == INF)
				cout << 0 << ' ';
			else
				cout << adjArr[i][j] << ' ';
		}
		cout << '\n';
	}
}