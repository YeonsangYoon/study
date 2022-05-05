/**********************************************************************
작성일 : 2022-05-05
문제 :
	마을을 연결하는 길의 유지비가 최소가 되도록 2개의 마을로 분리하라.
	이때 분리된 두 마을안에서 임의의 두 집 사이에 경로를 항상 존재한다.
풀이 :
	일단 주어진 마을을 기준으로 MST를 하나 구한다.
	그리고 해당 트리 내에서 가장 비용이 큰 간선을 제거하면 최소 비용을 가지는
	2개의 마을로 분리된다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + mlogm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
struct edge {
	int u, v, cost;
	bool operator<(const edge& a)const {
		return a.cost > cost;
	}
};
vector<edge> edgeList;

struct disJointSet { // union - find
	int parent[100001];
	void init() {
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (parent[a] == a) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
disJointSet djs;

int solve() {
	// mst 알고리즘
	djs.init();
	int ptr = 0, ret = 0, mCost = 0;

	for (int i = 0; i < n - 1; i++) {
		edge now = edgeList[ptr++];

		if (djs.find(now.u) != djs.find(now.v)) {
			djs.merge(now.u, now.v);
			mCost = max(mCost, now.cost);
			ret += now.cost;
		}
		else {
			i--;
		}
	}

	// 마을 분리하기 위해 간선 하나 제거(가장 큰 것)
	return ret - mCost;
}

void init() {
	// 변수 입력
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		edgeList.push_back({ a, b, c });
	}

	// 비용을 기준으로 오름차순으로 정렬
	sort(edgeList.begin(), edgeList.end());
}

int main(void) {
	fastio;
	init();

	cout << solve();
}