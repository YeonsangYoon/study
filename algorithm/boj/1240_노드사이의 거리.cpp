/**********************************************************************
작성일 : 2022-04-11
문제 :
	N개의 노드로 이루어진 트리와 M개의 노드 쌍이 주어질때 각 노드 쌍의 거리를 출력하라.
풀이 :
	트리에서 두 노드사이의 거리는 dfs, bfs로 구할 수 있지만, m개의 쌍에 대해
	구해야하기 때문에 더욱 효율적인 알고리즘을 사용할 수 있다.

	최소 공통 조상(LCA) 알고리즘을 이용하면 O(logn)의 시간복잡도로 두 노드간 거리를 구할 수 있다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pmax 15
#define MAX_NODE 1001
using namespace std;

int n, m;
int depth[MAX_NODE];
int parent[Pmax + 1][MAX_NODE];
int dist[Pmax + 1][MAX_NODE];
struct edge {
	int v, dist;
};
vector<edge> adjlist[MAX_NODE];

int get_dist(int a, int b) {
	int ret = 0;
	if (depth[a] < depth[b]) swap(a, b);

	for (int i = Pmax; i >= 0; i--) {
		if (depth[a] - (1 << i) >= depth[b]) {
			ret += dist[i][a];
			a = parent[i][a];
		}
	}

	if (a == b) return ret;

	for (int i = Pmax; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			ret += (dist[i][a] + dist[i][b]);
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return ret + dist[0][a] + dist[0][b];
}

void set_lca() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (edge& nex : adjlist[now]) {
			if (depth[nex.v] == 0 && nex.v != 1) {
				depth[nex.v] = depth[now] + 1;
				parent[0][nex.v] = now;
				dist[0][nex.v] = nex.dist;
				q.push(nex.v);
			}
		}
	}

	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			dist[i][j] = dist[i - 1][j] + dist[i - 1][parent[i - 1][j]];
		}
	}
}

void input() {
	cin >> n >> m;
	for (int i = 0; i < n - 1; i++) {
		int u, v, d;
		cin >> u >> v >> d;
		
		adjlist[u].push_back({ v, d });
		adjlist[v].push_back({ u, d });
	}
}

int main(void) {
	fastio;
	input();
	set_lca();

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;

		cout << get_dist(a, b) << '\n';
	}
}