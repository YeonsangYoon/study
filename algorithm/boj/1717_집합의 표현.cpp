/**********************************************************************
작성일 : 2022-5-21
문제 :
	n+1개의 집합이 있다. 합집합 연산과 두 원소가 같은 집합인지 확인하는 연산을
	수행한다고 할 때, 올바른 결과를 출력하라.
풀이 :
	간단한 union-find 구현
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;

int n, m;

struct disJointSet {
	int parent[MAX_SIZE];
	void init() {
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}
	int find(int u) {
		if (u == parent[u]) return u;
		return parent[u] = find(parent[u]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		parent[u] = v;
	}
};
disJointSet djs;

void init() {
	cin >> n >> m;
	djs.init();
}

int main(void) {
	fastio;
	init();
	
	for (int i = 0; i < m; i++) {
		int op, a, b;
		cin >> op >> a >> b;

		if (op == 0) {
			djs.merge(a, b);
		}
		else if (op == 1) {
			if (djs.find(a) == djs.find(b))
				cout << "YES\n";
			else
				cout << "NO\n";
		}
	}
}