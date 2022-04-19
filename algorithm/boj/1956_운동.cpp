/**********************************************************************
작성일 : 2022-04-19
문제 :
	각 간선의 거리가 다른 단방향 그래프가 주어질 때,
	이 그래플의 가장 짧은 사이클의 거리를 구하라. 만약 없으면 -1을 출력하라.
풀이 :
	플로이드 워셜을 통해 모든 정점 사이의 거리를 구한다.
	이 때 모든 정점에서 자기 자신으로 향하는 사이클의 거리를 확인한다.
시간 제한 : 2초
메모리 제한 : 192MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10000000
using namespace std;

int n, m;
int dist[401][401];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void init() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = INF;
		}
	}

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		dist[a][b] = c;
	}
}

int main(void) {
	fastio;

	init();
	floyd();

	int cycle = INF;
	for (int i = 1; i <= n; i++)
		cycle = min(cycle, dist[i][i]);

	if (cycle == INF)
		cout << -1;
	else
		cout << cycle;
}