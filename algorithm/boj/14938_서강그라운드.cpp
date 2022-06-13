/**********************************************************************
작성일 : 2022-6-13
문제 :
	양방향 그래프와 각 노드에 위치한 아이템 개수가 주어진다.
	이때, 예은이는 어떤 한 노드에 낙하하여 일정한 수색범위 내에 노드들에 방문하여
	아이템을 수집한다.
	예은이가 얻을 수 있는 아이템의 최대 개수를 구하라.
풀이 :
	모든 노드의 쌍에 대해 최단거리를 구한 뒤, 낙하지점에서 수색할 수 있는 노드를
	확인해야한다.
	따라서, 플로이드 - 워셜을 통해 모든 노드 쌍의 최단거리를 구한 뒤 최대값을 구했다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int n, m, r;
int items[101];
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
	cin >> n >> m >> r;
	for (int i = 1; i <= n; i++) {
		cin >> items[i];
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adjArr[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < r; i++) {
		int a, b, l;
		cin >> a >> b >> l;
		adjArr[a][b] = l;
		adjArr[b][a] = l;
	}
}

int main(void) {
	fastio;
	init();
	floyd();

	int maxItemCount = 0;
	for (int i = 1; i <= n; i++) {
		int tmp = items[i];
		for (int j = 1; j <= n; j++) {
			if (i != j && adjArr[i][j] <= m) {
				tmp += items[j];
			}
		}
		maxItemCount = max(maxItemCount, tmp);
	}
	cout << maxItemCount;
}