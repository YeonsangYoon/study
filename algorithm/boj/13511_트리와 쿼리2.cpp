/**********************************************************************
작성일 : 2022-3-07
문제 :
	Tree내에서의 최단경로와 경로 내의 k번째 노드를 구하는 다수의 쿼리를
	수행하라.
풀이 :
	lca 알고리즘을 기반으로 dist배열을 추가하여 경로까지 구할 수 있도록 설계하였다.
	참고로 root를 임의로 설정하여도 항상 같은 결과를 가진다.
	또한, 간선 cost의 최대값이 1,000,000이고 노드의 최대 개수가 100,000이기 때문에
	dist는 long long으로 설정한다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
#define Pmax 20
using namespace std;
typedef long long ll;

const int root = 1;
int n;
int depth[MAX];
int parent[Pmax + 1][MAX];
ll dist[Pmax + 1][MAX];

struct edge {
	int v, cost;
};
vector<edge> adjlist[MAX];

void set_parent(int p, int cur, int d) {
	for (edge& child : adjlist[cur]) {
		if (child.v != p) {
			parent[0][child.v] = cur;
			dist[0][child.v] = (ll)child.cost;
			depth[child.v] = depth[cur] + 1;
			set_parent(cur, child.v, d + 1);
		}
	}
}

ll get_cost(int a, int b) {
	// 트리의 경로 비용 구하기
	ll cost = 0;

	if (depth[a] < depth[b]) swap(a, b);

	for (int i = Pmax; i >= 0; i--) {
		if (depth[a] - (1 << i) >= depth[b]) {
			cost += dist[i][a];
			a = parent[i][a];
		}
	}

	if (a == b) return cost;

	for (int i = Pmax; i >= 0; i--) {
		if (parent[i][a] != parent[i][b]) {
			cost += (dist[i][a] + dist[i][b]);
			a = parent[i][a];
			b = parent[i][b];
		}
	}

	return cost + dist[0][a] + dist[0][b];
}

int get_node(int a, int b, int k) {
	if (k == 1) return a;	// k가 1이면 무조건 a

	// a, b의 lca 구하기
	int _a = a; int _b = b;
	if (depth[_a] < depth[_b]) swap(_a, _b);
	for (int i = Pmax; i >= 0; i--) {
		if (depth[_a] - (1 << i) >= depth[_b]) {
			_a = parent[i][_a];
		}
	}

	int lca;
	if (_a == _b) {
		lca = _a;
	}
	else {
		for (int i = Pmax; i >= 0; i--) {
			if (parent[i][_a] != parent[i][_b]) {
				_a = parent[i][_a];
				_b = parent[i][_b];
			}
		}
		lca = parent[0][_a];
	}

	// lca와 a, b의 depth 차이
	int upCnt = depth[a] - depth[lca];
	int downCnt = depth[b] - depth[lca];

	// k 범위에 따라서 a, b의 조상을 찾기
	if (k == upCnt + 1) {
		return lca;
	}
	else if (k == upCnt + downCnt + 1) {
		return b;
	}
	else if (k <= upCnt) {
		int target = depth[a] - k + 1;
		for (int i = Pmax; i >= 0; i--) {
			if (depth[a] - (1 << i) >= target) {
				a = parent[i][a];
			}
		}
		return a;
	}
	else {
		int target = depth[lca] + k - upCnt - 1;
		for (int i = Pmax; i >= 0; i--) {
			if (depth[b] - (1 << i) >= target) {
				b = parent[i][b];
			}
		}
		return b;
	}
}

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int u, v, c;
		cin >> u >> v >> c;
		adjlist[u].push_back({ v, c });
		adjlist[v].push_back({ u, c });
	}

	depth[root] = 1;
	set_parent(0, root, 1);

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
		int type, u, v; 
		cin >> type >> u >> v;

		if (type == 1) {
			cout << get_cost(u, v) << '\n';
		}
		else if (type == 2) {
			int k; cin >> k;
			cout << get_node(u, v, k) << '\n';
		}
	}
}