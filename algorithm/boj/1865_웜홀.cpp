/**********************************************************************
작성일 : 2022-03-28
문제 :
	그래프에서 음의 사이클이 존재하면 YES를 아니면 NO를 출력하라.
	도로는 양의 비용을 가지는 양방향 간선이고, 웜홀은 음의 비용을 가지는 단방향 간선이다.
풀이 :
	벨만 포드 알고리즘을 이용하여 음의 사이클을 검사하는 코드를 구현하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;
int n, m, w;
int dist[501];

struct edge {
	int s, e, cost;
};
vector<edge> adjlist;

bool bellman_ford(int start) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;

	for (int i = 0; i < n - 1; i++) {
		for (edge& now : adjlist) {
			if (now.s != INF && dist[now.e] > dist[now.s] + now.cost) {
				dist[now.e] = dist[now.s] + now.cost;
			}
		}
	}

	for (edge& now : adjlist) {
		if (dist[now.e] > dist[now.s] + now.cost)
			return true;
	}
	return false;
}

void init() {
	cin >> n >> m >> w;

	adjlist.clear();

	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adjlist.push_back({ s, e, t });
		adjlist.push_back({ e, s, t });
	}
	for (int i = 0; i < w; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adjlist.push_back({ s, e, -t });
	}
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();

		if (bellman_ford(1))
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}