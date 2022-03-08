/**********************************************************************
작성일 : 2022-3-08
문제 :
	N개의 노드를 가지는 트리의 간선이 주어질 때 다음과 같은 쿼리를 수행하라.
	query - r, u, v (r을 root로 하는 트리에서 u, v의 lca를 구하라)
풀이 :
	root가 1인 트리를 구현하고 매 쿼리마다 lca(r, u), lca(r, v) lca(u, v) 세개 중
	가장 깊이가 깊은 것이 답이 된다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
#define Pmax 20
using namespace std;

const int root = 1;
int n;
int depth[MAX_SIZE];
int parent[Pmax + 1][MAX_SIZE];
vector<int> adjlist[MAX_SIZE];

int lca(int a, int b) {
	if (depth[a] < depth[b]) swap(a, b);

	for (int i = Pmax; i >= 0; i--) {
		if (depth[a] - (1 << i) >= depth[b]) {
			a = parent[i][a];
		}
	}

	if (a == b) return a;

	for (int i = Pmax; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return parent[0][a];
}

void set_tree(int p, int cur) {
	for (int& child : adjlist[cur]) {
		if (child != p) {
			depth[child] = depth[cur] + 1;
			parent[0][child] = cur;
			set_tree(cur, child);
		}
	}
}

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}

	depth[root] = 1;
	set_tree(0, root);

	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[i][j] = parent[i - 1][parent[i - 1][j]];
		}
	}
}

int main() {
	fastio;

	init();

	int queryCnt; cin >> queryCnt;
	for (int i = 0; i < queryCnt; i++) {
		int r, u, v;
		cin >> r >> u >> v;
		
		int uv = lca(u, v);
		int ru = lca(r, u);
		int rv = lca(r, v);

		int ans;
		if (depth[uv] > depth[ru]) {
			if (depth[uv] > depth[rv])
				ans = uv;
			else
				ans = rv;
		}
		else {
			if (depth[ru] > depth[rv])
				ans = ru;
			else
				ans = rv;
		}

		cout << ans << '\n';
	}
}
