/**********************************************************************
작성일 : 2022-5-29
문제 :
	가중치를 가지는 방향그래프가 주어질 때, 시작정점에서 다른 모든 정점으로의
	최단거리를 구하라.
풀이 :
	양의 가중치를 가지고 시작정점이 정해져 있기 때문에 '다익스트라'를 사용하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(vloge)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int v, e, start;
int dist[20001];
struct node {
	int u, cost;
	bool operator<(const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adjlist[20001];

void dijkstar() {
	for (int i = 1; i <= v; i++)
		dist[i] = INF;
	dist[start] = 0;

	priority_queue<node> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.u] < now.cost) continue;

		for (node& edge : adjlist[now.u]) {
			if (dist[edge.u] > dist[now.u] + edge.cost) {
				dist[edge.u] = dist[now.u] + edge.cost;
				pq.push({ edge.u, dist[edge.u] });
			}
		}
	}
}

void init() {
	cin >> v >> e >> start;

	for (int i = 0; i < e; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjlist[u].push_back({ v, w });
	}
}

int main(void) {
	fastio;
	init();
	dijkstar();

	for (int i = 1; i <= v; i++) {
		if (dist[i] == INF)
			cout << "INF\n";
		else
			cout << dist[i] << '\n';
	}
}