/**********************************************************************
작성일 : 2022-6-18
문제 :
	N개의 도시가 있고, 각 도시를 연결하는 M개의 버스 노선이 있다.
	어떤 버스 노선의 경우 가중치가 0이거나 음수일 수 있다.
	이때, 1번 도시에서 나머지 도시로 가는 최단거리를 구하라. 
풀이 :
	벨만 포드 기본 풀이
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000000
using namespace std;
typedef long long ll;

int n, m;
ll dist[501];
struct edge {
	int s, e;
	ll cost;
};
vector<edge> edgeList;

bool bellman_ford() {
	for (int i = 2; i <= n; i++)
		dist[i] = INF;
	dist[1] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (edge& e : edgeList) {
			if (dist[e.s] == INF) 
				continue;
			dist[e.e] = min(dist[e.e], dist[e.s] + e.cost);
		}
	}

	for (edge& e : edgeList) {
		if (dist[e.s] != INF && dist[e.e] > dist[e.s] + e.cost)
			return false;
	}
	return true;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e; ll cost;
		cin >> s >> e >> cost;
		edgeList.push_back({ s, e, cost });
	}
}

int main(void) {
	fastio;
	init();

	if (bellman_ford()) {
		for (int i = 2; i <= n; i++) {
			if (dist[i] == INF)
				cout << -1 << '\n';
			else
				cout << dist[i] << '\n';
		}
	}
	else {
		cout << -1;
	}
}