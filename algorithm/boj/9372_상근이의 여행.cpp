/**********************************************************************
작성일 : 2022-8-08
문제 :
	그래프내에서 모든 노드를 방문하기 위해 거쳐야할 간선의 최소 개수를 구하라.
풀이 :
	모든 간선의 비용이 1인 mst를 구하는 문제로 해석했다.
	mst 알고리즘을 통하여 문제를 해결하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct disJointSet {
	int parent[1001];
	void init(int a) {
		for (int i = 1; i <= a; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
struct edge {
	int u, v;
};

int n, m;
disJointSet djs;
vector<edge> edgeList;

void init() {
	cin >> n >> m;
	djs.init(n);

	edgeList.clear();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		edgeList.push_back({ a, b });
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

		int ans = 0;
		for (edge& e : edgeList) {
			if (djs.find(e.u) != djs.find(e.v)) {
				djs.merge(e.u, e.v);
				ans++;
			}
		}
		cout << ans << '\n';
	}
}