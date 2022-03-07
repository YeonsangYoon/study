/**********************************************************************
작성일 : 2022-3-07
문제 :
	트리의 노드 개수와 간선이 주어졌을 때 두 노드의 거리를 구하는 query를 
	수행하는 것을 구현하라
풀이 :
	기본적인 LCA 알고리즘에 2^i번째 부모까지의 거리를 저장하는 dist배열을
	추가적으로 구현하여 이를 통해 구한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pmax 20
#define MAX_SIZE 40001
using namespace std;

const int root = 1;
int n;
int depth[MAX_SIZE];
int dist[Pmax + 1][MAX_SIZE];
int parent[Pmax + 1][MAX_SIZE];

struct edge {
	int v, cost;
};
vector<edge> adjlist[MAX_SIZE];

int get_dist(int a, int b) {
	// LCA algorithm
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

void set_tree(int p, int cur) {
	// dfs algorithm
	for (edge& child : adjlist[cur]) {
		if (child.v != p) {
			parent[0][child.v] = cur;
			dist[0][child.v] = child.cost;
			depth[child.v] = depth[cur] + 1;
			set_tree(cur, child.v);
		}
	}
}
void init() {
	cin >> n;
	for (int i = 1; i < n; i++) {
		int u, v, cost;
		cin >> u >> v >> cost;
		adjlist[u].push_back({ v, cost });
		adjlist[v].push_back({ u, cost });
	}
	
	depth[root] = 1;
	set_tree(0, root);
	
	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
			dist[i][j] = dist[i - 1][j] + dist[i - 1][parent[i - 1][j]];
		}
	}
}

int main() {
	fastio;

	init();

	int queryCnt; cin >> queryCnt;
	for (int i = 0; i < queryCnt; i++) {
		int u, v;
		cin >> u >> v;
		cout << get_dist(u, v) << '\n';
	}
}