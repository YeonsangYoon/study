/**********************************************************************
작성일 : 2022-5-22
문제 :
	N개의 도시에 전기를 공급하고자한다. 이 N개의 도시 중 K개의 도시는
	발전소 건물이 있어 전기를 생산할 수 있다.
	M개의 간선 중 적절한 것을 선택하여 모든 도시가 전기를 공급받도록 하는 
	최소비용을 구하라.	
풀이 :
	MST를 응용하는 문제이다. 발전소가 k개 있기 때문에 굳이 모든 도시를 연결할 필요가 없다.
	따라서 기준 mst처럼 n-1개의 간선을 선택하는 것과 달리 n-k개만을 선택해야한다. (k개의 트리를 만듬)
	크루스칼 알고리즘을 이용하여 mst를 구현하였고, k개의 발전소는 이미 연결되어있는 것처럼 초기화하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(mlogm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, k;
struct edge {
	int u, v, w;
	bool operator<(const edge& a) const {
		return a.w > w;
	}
};
edge edgeList[100001];

struct disJoint {
	int parent[1001];
	void init() {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (parent[u] == u) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
};
disJoint djs;

int get_min_cost() {
	int cost = 0, ptr = 0;
	for (int i = 0; i < n - k; i++) {
		edge now = edgeList[ptr++];

		if (djs.find(now.u) == djs.find(now.v)) {
			i--;
			continue;
		}
		else {
			djs.merge(now.u, now.v);
			cost += now.w;
		}
	}
	return cost;
}

void init() {
	cin >> n >> m >> k;

	djs.init();

	for (int i = 0; i < k; i++) {
		int g; cin >> g;
		djs.merge(0, g);
	}

	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		edgeList[i] = { u, v, w };
	}
	sort(edgeList, edgeList + m);
}

int main(void) {
	fastio;
	init();

	cout << get_min_cost();
}