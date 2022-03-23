/**********************************************************************
작성일 : 2022-03-23
문제 :
	트리와 각 간선의 가중치가 주어질때 트리의 지름을 구하라.
	트리의 지름이란 두 노드 사이의 경로 중 가장 긴 것의 길이이다.
풀이 :
	임의의 노드 x에서 가장 먼 노드 y를 구하고, y에서 가장 먼 노드인 z가 있다.
	이때 트리의 지름은 y와 z의 거리이다.
	다익스트라를 통해 가장 먼 노드를 구한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n;
int dist[10001];
struct node {
	int v, cost;
	bool operator<(const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adjlist[10001];

int dijkstra(int s) {
	for (int i = 1; i <= n; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;

	priority_queue<node> pq;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (now.cost > dist[now.v]) continue;
		for (node& edge : adjlist[now.v]) {
			if (now.cost + edge.cost < dist[edge.v]) {
				dist[edge.v] = now.cost + edge.cost;
				pq.push({ edge.v, dist[edge.v] });
			}
		}
	}

	int ret = 0;
	int d = 0;
	for (int i = 1; i <= n; i++) {
		if (d < dist[i] && i != s) {
			ret = i;
			d = dist[i];
		}
	}
	return ret;
}

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adjlist[u].push_back({ v, cost });
		adjlist[v].push_back({ u, cost });
	}
}

int main() {
	fastio;

	init();

	if (n == 1) {
		cout << 0;
		return 0;
	}

	int x = 1;
	int y = dijkstra(x);
	int z = dijkstra(y);

	cout << dist[z];
}