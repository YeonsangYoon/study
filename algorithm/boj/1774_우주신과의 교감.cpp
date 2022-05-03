/**********************************************************************
작성일 : 2022-05-03
문제 :
	n개의 노드가 있고 각 노드의 좌표가 주어진다고 한다.
	n개의 노드가 모두 서로 연결되도록 통로를 설치하려할 때 선택할 수 있는 최소 비용을 구하라.
	이미 연결된 m개의 노드 쌍이 주어진다.
풀이 :
	mst를 사용하여 최소 비용을 구한다. 
	n의 최대값이 1000이기 때문에 모든 노드의 간선을 구하더라도 가능하다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

// variable
int n, m;
struct pos {
	ll x, y;
};
pos posList[1001];
struct edge {
	int a, b;
	double dist;
	bool operator<(const edge& a)const {
		return a.dist > dist;
	}
};
vector<edge> edgeList;

struct disJointSet {	// union - find 
	int parent[1001];
	void init() {
		for (int i = 0; i <= 1000; i++)
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

double solve() {
	// mst 알고리즘
	djs.init();

	int cnt = 0;
	double totalDist = 0.0;
	for (int i = 0; i < (int)edgeList.size(); i++) {
		if (cnt == n - 1) break;

		if (djs.find(edgeList[i].a) != djs.find(edgeList[i].b)) {
			djs.merge(edgeList[i].a, edgeList[i].b);
			cnt++;
			totalDist += edgeList[i].dist;
		}
	}

	return totalDist;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {	// 좌표 입력
		ll x, y;
		cin >> x >> y;
		posList[i] = { x, y };
	}

	for (int i = 1; i <= n; i++) {	// 간선 계산
		for (int j = i + 1; j <= n; j++) {
			ll xdiff = abs(posList[i].x - posList[j].x);
			ll ydiff = abs(posList[i].y - posList[j].y);
			double dist = sqrt(xdiff * xdiff + ydiff * ydiff);

			edgeList.push_back({ i, j, dist });
		}
	}
	for (int i = 0; i < m; i++) {	// 이미 연결된 간선도 추가
		int a, b;
		cin >> a >> b;
		edgeList.push_back({ a, b, 0.0 });
	}
	sort(edgeList.begin(), edgeList.end());	// dist 기준 간선 정렬
}

int main(void) {
	fastio;
	init();		// 변수 입력 및 초기화

	cout << fixed;
	cout.precision(2);
	cout << solve();
}