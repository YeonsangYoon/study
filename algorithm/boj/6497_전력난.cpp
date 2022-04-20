/**********************************************************************
작성일 : 2022-04-20
문제 :
	m개의 도시들이 n개의 도로들로 연결되어 그래프를 이루고 있다.
	각 도로는 양방향 간선이며 모든 도시들이 연결되어있다.
	이때 전기를 절약하기 위해 모든 도시가 연결되기 위한 최소한의 도로만을 남기고
	도로를 폐쇄하고자 한다. 이 때 절약할 수 있는 최대 비용을 구하라.
풀이 :
	모든 도시를 연결하는 최소 비용을 구한 뒤 이를 모든 간선의 합에서 빼준다.
	최소 비용은 크루스칼 알고리즘을 이용하여 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(TC * nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int m, n;
int totalCost;
struct edge {
	int u, v, cost;
	bool operator<(const edge& a) const {
		return a.cost > cost;
	}
};
edge edgeList[200001];

struct disJointSet {
	// union - find
	int parent[200001];
	void init() {
		for (int i = 0; i < m; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (parent[a] == a) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
disJointSet djs;

int mst() {
	// 최소 신장 트리의 비용 구하기
	int ret = 0;
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		if (cnt == m - 1) break;

		edge& now = edgeList[i];

		if (djs.find(now.u) != djs.find(now.v)) {
			djs.merge(now.u, now.v);
			ret += now.cost;
			cnt++;
		}
	}
	return ret;
}

void init() {
	// 테스트 케이스 초기화 함수
	djs.init();
	totalCost = 0;

	for (int i = 0; i < n; i++) {
		int x, y, z;
		cin >> x >> y >> z;
		edgeList[i] = { x, y, z };
		totalCost += z;
	}
	sort(edgeList, edgeList + n);
}

int main(void) {
	fastio;

	while (1) {
		cin >> m >> n;
		
		if (m == 0 && n == 0) break;

		init();
		cout << totalCost - mst() << '\n';
	}
}