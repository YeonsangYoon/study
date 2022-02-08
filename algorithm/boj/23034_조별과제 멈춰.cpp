/**********************************************************************
작성일 : 2022-2-08
문제 :
	팀장 2명에게 공지사항을 전달했을 때 모든 조원에게 전달하는 최소비용을 구하라
풀이 :
	쿼리형 문제로 팀장 2명이 매 쿼리마다 바뀜(최대 쿼리 개수 : 10000)
	1. 전체 조원을 연결하고 최소비용을 가지는 간선들을 선택한다.
		=> MST를 이용하여 구한다. 
	2. 매 쿼리에서 선택되는 팀장들 사이의 간선들 중 최대값을 선택해 빼준다.
		=> dfs를 이용하여 tree를 순회하고 그 과정에서 최대값을 구한다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O((n+m)logm + q*n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int totalCost;			// mst 전체 간선 비용

struct disJointSet {	// union-find 자료구조
	vector<int> parent;

	disJointSet(int n) : parent(n + 1) {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int n) {
		if (parent[n] == n)
			return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);

		if (a == b) return;

		parent[a] = b;
	}
};
struct edge {
	int a, b, cost;
};
struct cmp {
	bool operator()(edge& a, edge& b) {
		return a.cost > b.cost;
	}
};
struct treeEdge {
	int next, cost;
};
vector<treeEdge> adjlist[1001];

int mst(int n, int m) {		
	// minimum spanning tree 구하기
	int retval = 0;

	priority_queue<edge, vector<edge>, cmp > pq;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}

	disJointSet djs(n);

	int cnt = n - 1;
	while (cnt > 0) {
		edge now = pq.top(); pq.pop();

		if (djs.find(now.a) == djs.find(now.b))
			continue;

		djs.merge(now.a, now.b);
		retval += now.cost;
		cnt--;

		// tree 간선만 따로 생성
		adjlist[now.a].push_back({ now.b, now.cost });
		adjlist[now.b].push_back({ now.a, now.cost });
	}
	return retval;
}

void dfs(int cur, int prev, int target, int maxCost) {
	if (cur == target) {
		cout << totalCost - maxCost << '\n';
		return;
	}

	for (treeEdge& next : adjlist[cur]) {
		if (next.next == prev)
			continue;
		dfs(next.next, cur, target, max(maxCost, next.cost));
	}
}

int main() {
	fastio;

	int n, m;
	cin >> n >> m;

	totalCost = mst(n, m);

	int query; cin >> query;
	for (int i = 0; i < query; i++) {
		int tl1, tl2;
		cin >> tl1 >> tl2;

		dfs(tl1, 0, tl2, 0);
	}
}