/**********************************************************************
작성일 : 2022-3-14
문제 :
	로봇의 부품에 대한 2가지 지시를 할 때 올바른 답을 출력하라.
	1. 서로 다른 부품 2개를 말해주며, 두 부품이 같은 로봇의 부품이라고 한다.
	2. 부품 i에 대하여 지금까지 알아낸 robot(i)의 부품이 몇개인지 출력한다.
풀이 :
	union - find에 cnt 정보를 추가하여 구현하였다. 
시간 제한 : 4초
메모리 제한 : 1024MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;

struct disJointSet {
	int parent[MAX_SIZE];
	int cnt[MAX_SIZE];

	void init() {
		for (int i = 1; i < MAX_SIZE; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int u, int v) {
		u = find(u); v = find(v);
		if (u == v) return;
		parent[u] = v;
		cnt[v] += cnt[u];
	}
};
disJointSet djs;

int main() {
	fastio;

	djs.init();
	int n; cin >> n;

	for (int i = 0; i < n; i++) {
		char cmd; cin >> cmd;

		if (cmd == 'I') {
			int a, b;
			cin >> a >> b;
			djs.merge(a, b);
		}
		else if (cmd == 'Q') {
			int c; cin >> c;
			cout << djs.cnt[djs.find(c)] << '\n';
		}
	}
}