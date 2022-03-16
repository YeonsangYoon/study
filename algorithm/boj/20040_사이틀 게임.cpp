/**********************************************************************
작성일 : 2022-3-16
문제 :
	n개의 점을 m개의 선분으로 연결한다고 할 때 몇번째 선분에서 사이클이
	처음으로 생기는 지 출력하라. 만약 사이클이 생기지 않으면 0을 출력한다.
풀이 :
	union - find를 통해 구현한다. 
	추가할 선분의 두 원소가 같은 집합에 이미 속해져 있는 경우 사이클이 생성된다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;

struct disJointSet {
	int *parent;

	void init(int n) {
		parent = new int[n];
		for (int i = 0; i < n; i++)
			parent[i] = i;
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
};
disJointSet djs;

int solve() {
	for (int i = 1; i <= m; i++) {
		int u, v;
		cin >> u >> v;

		if (djs.find(u) == djs.find(v))
			return i;
		djs.merge(u, v);
	}
	return 0;
}

void init() {
	cin >> n >> m;
	djs.init(n);
}

int main() {
	fastio;

	init();
	cout << solve();
}