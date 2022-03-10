/**********************************************************************
작성일 : 2022-3-10
문제 :
	주인공이 거짓말을 할 수 있는 파티의 개수를 구하라.
	거짓말을 할 수 있는 파티는 진실을 아는 사람이 없는 파티이다.
풀이 :
	진실을 아는 사람과 모르는 사람을 구분하기 위해 서로소 집합을 구현하였다.
	진실을 아는 사람과 같이 파티를 하는 사람 또한 진실을 알게 되므로 merge를 수행하였다.
	위를 토대로 파티에 있는 모든 사람이 진실을 모르는 사람인 경우에만 cnt를 증가하여 구했다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
vector<int> party[51];

struct disJointSet {
	int parent[51];

	void init() {
		for (int i = 0; i <= 50; i++)
			parent[i] = i;
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
disJointSet djs;

void init() {
	djs.init();
	cin >> n >> m;

	int cnt; cin >> cnt;	// cnt : 진실을 아는 사람 개수
	for (int i = 0; i < cnt; i++) {
		int t; cin >> t;
		djs.merge(t, 0);
	}

	for (int i = 0; i < m; i++) {
		cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int p; cin >> p;
			party[i].push_back(p);
		}
		if (cnt >= 2) {
			for (int j = 1; j < cnt; j++) {
				djs.merge(party[i][0], party[i][j]);
			}
		}
	}
}

int solve() {
	int ret = m;

	for (int i = 0; i < m; i++) {
		for (int& person : party[i]) {
			if (djs.find(person) == djs.find(0)) {
				ret--;
				break;
			}
		}
	}
	return ret;
}

int main() {
	fastio;

	init();
	cout << solve();
}