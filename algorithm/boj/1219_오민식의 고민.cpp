/**********************************************************************
작성일 : 2022-6-23
문제 :
	민식이는 N개의 도시를 오가면서 물건을 팔고자 한다.
	도시를 연결하는 교통수단의 정보와 각 도시를 방문했을 때의 수익이 주어진다.
	도착 도시에 도착할 때, 가지고 있는 돈의 액수의 최댓값을 구하라.
	도착 도시에 갈 수 없는 경우에는 gg를 출력하고, 무한대의 돈을 벌 수 있으면 Gee를 출력하라.
풀이 :
	교통 수단의 비용과 돈을 버는 비용을 합쳐서 인접리스트를 만들었다.
	최단 거리는 벨만 포드 알고리즘을 활용하여 구하였다.
	이때, 음의 사이클이 존재하더라도 시작 정점에서 도착 정점으로의 경로에
	음의 사이클이 없는 경우에는 그대로 dist값을 출력하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 10000000000
#define MAXV 50

typedef long long ll;

int n, m, s, e;
ll dist[MAXV];
struct node {
	int u, cost;
};
vector<node> adjlist[MAXV];
bool visited[MAXV];

bool bfs(int start) {
	memset(visited, false, sizeof(visited));
	visited[start] = true;

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == e)
			return true;

		for (node& edge : adjlist[now]) {
			if (!visited[edge.u]) {
				q.push(edge.u);
				visited[edge.u] = true;
			}
		}
	}
	return false;
}

bool bellman_ford() {
	for (int i = 0; i < n - 1; i++) {
		bool change = false;
		for (int j = 0; j < n; j++) {
			for (node& edge : adjlist[j]) {
				if (dist[j] != INF && dist[edge.u] > dist[j] + edge.cost) {
					dist[edge.u] = dist[j] + edge.cost;
					change = true;
				}
			}
		}
		if (!change)
			return false;
	}

	for (int i = 0; i < n; i++) {
		for (node& edge : adjlist[i]) {
			if (dist[i] != INF && dist[edge.u] > dist[i] + edge.cost) {
				if (bfs(edge.u))
					return true;
			}
		}
	}
	return false;
}

void init() {
	cin >> n >> s >> e >> m;

	for (int i = 0; i < n; i++)
		dist[i] = INF;

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjlist[u].push_back({ v, w });
	}

	for (int i = 0; i < n; i++) {
		int pay; cin >> pay;
		if (i == s)
			dist[s] = -pay;
		for (int j = 0; j < n; j++) {
			for (node& edge : adjlist[j]) {
				if (edge.u == i)
					edge.cost -= pay;
			}
		}
	}
}

int main(void) {
	fastio;
	init();

	bool cycle = bellman_ford();

	if (dist[e] == INF)
		cout << "gg";
	else if (cycle)
		cout << "Gee";
	else
		cout << -dist[e];
}