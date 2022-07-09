/**********************************************************************
작성일 : 2022-07-09
작성자 : 윤연상
문제 :
	n개의 섬으로 이루어진 나라가 있다. 
	몇 개의 섬 사이에는 다리가 설치되어있고, 각 다리는 양방향이고 중량제한이 있다.
	이때, 어떤 섬 s에서 e로 가고자 할 때, 한 번에 옮길 수 있는 물품들의 중량의 최대값을 구하라.
풀이 :
	특정 정점의 연결성을 확인하는 문제이기 때문에 다양한 알고리즘이 사용가능하다.
	dfs, bfs도 사용가능하지만, 이 문제의 경우 되도록이면 중량제한이 큰 간선들만 사용하여
	두 정점을 연결성을 확보해야한다.
	따라서 간선들의 중량제한을 기준으로 최대힙을 만들고 하나씩 꺼내가면서 그래프를 그려가본다고 생각해보자.
	union-find를 사용하여 각 간선을 꺼낼 때마다 연결성을 표현하고, 만약 연결이 확인 되는 즉시 사이클을 종료하면된다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(mlogm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_N 100000

struct edge {
	int u, v, limit;
	bool operator<(const edge& a) const {
		return limit < a.limit;
	}
};
struct disJointSet {
	int parent[MAX_N + 1];
	void init(int n) {
		for (int i = 1; i <= n; i++)
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

int n, m, s, e;
disJointSet djs;
priority_queue<edge> pq;

int solve() {
	while (!pq.empty()) {
		edge now = pq.top(); pq.pop();
		djs.merge(now.u, now.v);

		if (djs.find(s) == djs.find(e))
			return now.limit;
	}
	return -1;	// (연결성 없는 경우, 입력은 무조건 연결성 있는 경우만 주어짐)
}

void init() {
	cin >> n >> m;
	djs.init(n);

	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		pq.push({ a, b, c });
	}
	cin >> s >> e;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}