/**********************************************************************
작성일 : 2022-6-24
문제 :
	음의 간선을 가지는 단방향 그래프가 주어진다.
	정점 1에서 정점 n으로 최단거리로 이동하고자 할 때, 최단거리를 가지는 경로를 출력하라.
	만약 최적의 경로가 존재하지 않는 상황이 발생했을 때는 -1을 출력하라.
풀이 :
	벨만 포드 알고리즘을 활용하여 최단거리를 구하고, parent배열을 활용하여
	path를 구하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAXV 100
#define INF 2000000001

typedef long long ll;

int n, m;
int parent[MAXV + 1];
int dist[MAXV + 1];
struct node {
	int v, cost;
};
vector<node> adjlist[MAXV + 1];

bool bfs(int start) {
	bool visited[MAXV + 1];
	memset(visited, false, sizeof(visited));
	visited[start] = true;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now == n) return true;

		for (node& e : adjlist[now]) {
			if (!visited[e.v]) {
				q.push(e.v);
				visited[e.v] = true;
			}
		}
	}
	return false;
}

bool bellman_ford() {
	for (int i = 2; i <= n; i++)
		dist[i] = INF;

	for (int i = 0; i < n - 1; i++) {
		bool change = false;
		for (int s = 1; s <= n; s++ ) {
			for (node& e : adjlist[s]) {
				if (dist[s] != INF && dist[e.v] > dist[s] + e.cost) {
					dist[e.v] = dist[s] + e.cost;
					parent[e.v] = s;
					change = true;
				}
			}
		}
		if (!change)
			return false;
	}

	for (int s = 1; s <= n; s++)
		for (node& e : adjlist[s])
			if (dist[s] != INF && dist[e.v] > dist[s] + e.cost)
				if (bfs(e.v))
					return true;
	return false;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjlist[u].push_back({ v, -w });
	}
}

int main(void) {
	fastio;
	init();

	bool cycle = bellman_ford();

	if (cycle || dist[n] == INF) {
		cout << -1;
	}
	else {
		stack<int> path;
		path.push(n);

		while (path.top() != 1)
			path.push(parent[path.top()]);

		while (!path.empty()) {
			cout << path.top() << ' ';
			path.pop();
		}
	}
}