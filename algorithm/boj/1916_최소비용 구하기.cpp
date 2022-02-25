/**********************************************************************
작성일 : 2022-2-25
문제 :
	단방향 그래프와 각 간선의 비용이 주어질 때 출발노드에서 도착노드로 가기 위한
	최소 비용을 구하라
풀이 :
	heap과 다익스트라를 구현하여 문제를 풀었다.
시간 제한 : 0.5초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1001
#define INF 2000000000
using namespace std;

int n, m;
int s, e;
int dist[MAX_N];
int adjlist[MAX_N][MAX_N];

struct node {
	int v, dist;
};
struct HEAP {
	int sz;
	node data[MAX_N * MAX_N];

	void init() { sz = 0; }
	void push(node val) {
		data[sz] = val;
		int cur = sz++;

		while (cur > 0 && data[cur].dist < data[(cur - 1) / 2].dist) {
			node tmp = data[cur];
			data[cur] = data[(cur - 1) / 2];
			data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
	}
	node pop() {
		node ret = data[0];
		data[0] = data[--sz];

		int cur = 0;
		int child;
		while (cur * 2 + 1 < sz) {
			if (cur * 2 + 2 == sz)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1].dist < data[cur * 2 + 2].dist) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur].dist < data[child].dist) break;

			node tmp = data[cur];
			data[cur] = data[child];
			data[child] = tmp;
			cur = child;
		}
		return ret;
	}
};
HEAP heap;

int dijkstra() {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;

	heap.init();
	heap.push({ s, 0 });

	while (heap.sz > 0) {
		node now = heap.pop();

		if (dist[now.v] < now.dist) continue;

		for (int i = 1; i <= n; i++) {
			if (adjlist[now.v][i] == INF) continue;

			if (now.dist + adjlist[now.v][i] < dist[i]) {
				dist[i] = now.dist + adjlist[now.v][i];
				heap.push({ i, dist[i] });
			}
		}
	}
	return dist[e];
}
void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adjlist[i][j] = INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a][b] = min(adjlist[a][b], c);
	}
	cin >> s >> e;
}
int main() {
	fastio;

	init();
	cout << dijkstra();

}