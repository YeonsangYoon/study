/**********************************************************************
작성일 : 2022-2-09
문제 :
	입구에서 출발하여 n개의 건물을 모두 방문하려한다.
	각 건물을 연결하는 길은 오르막길과 내리막길이 있다.
	만약 건물들을 방문하면서 k번 오르막길을 지난다고 하면 받는 피로도는 k^2이다.
	이때 받을 수 있는 최고의 피로도와 최저의 피로도의 차이를 구하라
풀이 :
	maxheap, minheap을 두개 구현하여 mst를 두번 수행한다.
	두 mst 결과를 통해 답을 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;	// 건물의 개수 N, 도로의 개수 M

struct disJointSet {
	vector<int> parent;
	
	void init(int n) {
		vector<int>().swap(parent);
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
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

struct road {
	int v1, v2, cost;
};
struct cmp1 {
	bool operator()(road& a, road& b) {
		return a.cost > b.cost;
	}
};
struct cmp2 {
	bool operator()(road& a, road& b) {
		return a.cost < b.cost;
	}
};
priority_queue<road, vector<road>, cmp1> minPq;
priority_queue<road, vector<road>, cmp2> maxPq;

void init() {
	cin >> n >> m;
	for (int i = 0; i < m + 1; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		maxPq.push({ a, b, c ? 0 : 1 });
		minPq.push({ a, b, c ? 0 : 1 });
	}
}

int solve() {
	disJointSet djs;
	djs.init(n);

	int best = 0;
	for (int i = 0; i < n; i++) {
		road now = minPq.top(); minPq.pop();

		if (djs.find(now.v1) == djs.find(now.v2)) {
			i--;
			continue;
		}
		djs.merge(now.v1, now.v2);
		best += now.cost;
	}

	djs.init(n);
	int worst = 0;
	for (int i = 0; i < n; i++) {
		road now = maxPq.top(); maxPq.pop();

		if (djs.find(now.v1) == djs.find(now.v2)) {
			i--;
			continue;
		}
		djs.merge(now.v1, now.v2);
		worst += now.cost;
	}

	return worst * worst - best * best;
}

int main() {
	fastio;

	init();
	cout << solve();

	return 0;
}