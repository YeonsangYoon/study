/**********************************************************************
작성일 : 2022-2-08
문제 :
	주어진 그래프의 최소 스패닝 트리를 구하라
풀이 :
	union-find와 heap을 통해 구현한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

// union-find 구현
struct disJointSet {
	vector<int> parent;

	disJointSet(int n) : parent(n + 1) {
		for (int i = 0; i <= n; i++)
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
// 간선 heap 구현
struct edge {
	int v1, v2, cost;
};
struct cmp {
	bool operator()(edge& a, edge& b) {
		return a.cost > b.cost;
	}
};
priority_queue<edge, vector<edge>, cmp> pq;

void init(int e) {
	for (int i = 0; i < e; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}
}
int mst(int n) {
	int ret = 0;
	disJointSet djs(n);

	for (int i = 0; i < n - 1; i++) {
		edge now = pq.top(); pq.pop();

		if (djs.find(now.v1) == djs.find(now.v2)) {
			i--;
			continue;
		}

		djs.merge(now.v1, now.v2);
		ret += now.cost;
	}
	return ret;
}

int main() {
	fastio;

	int v, e;
	cin >> v >> e;

	init(e);
	cout << mst(v);
}