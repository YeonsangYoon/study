/**********************************************************************
작성일 : 2022-03-20
문제 :
	양방향 그래프가 주어졌을 때 1번부터 n까지의 최단경로 중
	반드시 v1, v2 두 노드를 통과해야하는 최단경로를 구하라.
풀이 :
	v1, v2를 방문하는 총 2가지 경우의 수 중 작은 것을 구했다.
	경로 1 : (1 -> v1 -> v2 -> n)
	경로 2 : (1 -> v2 -> v1 -> n)
	다익스트라를 통해 각 구간의 최단경로를 구하고 두 경로 중 작은 것을 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 600000000
using namespace std;

int n, m;
int v1, v2;
struct node {
	int v, cost;
	bool operator<(const node& a) const{
		return a.cost < cost;
	}
};
vector<node> adjlist[801];

int dijkstra(int s, int e) {
	int dist[801];
	for (int i = 1; i <= n; i++) dist[i] = INF;
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

	return dist[e];
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adjlist[u].push_back({ v, cost });
		adjlist[v].push_back({ u, cost });
	}
	cin >> v1 >> v2;
}

int main() {
	fastio;

	init();
	
	int first = dijkstra(1, v1) + dijkstra(v1, v2) + dijkstra(v2, n);
	int second = dijkstra(1, v2) + dijkstra(v2, v1) + dijkstra(v1, n);

	if (first >= INF && second >= INF)
		cout << -1;
	else
		cout << min(first, second);
}