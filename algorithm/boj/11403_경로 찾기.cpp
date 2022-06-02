/**********************************************************************
작성일 : 2022-6-02
문제 :
	n개의 정점이 있을 때, 모든 정점 쌍에 대하여 두 정점 사이의 경로가 있는 지 구하라.
풀이 :
	플로이드 워셜을 통해 모든 쌍의 최단거리를 구하고, 해당 값을 통해 답을 구한다.
	
	(union-find를 통해 연결된 노드들의 집합을 구하려 했지만, 
	자기 자신으로 가는 경로의 유무는 파악할 수 없었다)
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 100000000
using namespace std;

int n;
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
	cin >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adjArr[i][j] = INF;
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int edge; cin >> edge;
			if (edge == 1)
				adjArr[i][j] = 1;
		}
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
				cout << 1 << ' ';
		}
		cout << '\n';
	}
}