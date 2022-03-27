/**********************************************************************
작성일 : 2022-03-27
문제 :
	N개의 마을에 학생이 각 1명있고, 그 중 마을 X에서 파티가 열린다.
	이때 파티에 갔다오는 데 걸리는 시간 중 가장 오래걸리는 학생의 시간을 구하라.
풀이 :
	다익스트라를 사용하여 1~n -> x로 가는 최단거리와 x -> 1 ~ n으로 가는 최단거리를
	구했다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nmlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n, m, x;
int dist[1001];
int iToX[1001];
struct node {
	int v, time;
	bool operator<(const node& a) const {
		return a.time < time;
	}
};
vector<node> adjlist[1001];

int dijkstra(int s, int e) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[s] = 0;

	priority_queue<node> pq;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (now.time > dist[now.v]) continue;
		for (node& edge : adjlist[now.v]) {
			if (now.time + edge.time < dist[edge.v]) {
				dist[edge.v] = now.time + edge.time;
				pq.push({ edge.v, dist[edge.v] });
			}
		}
	}

	return dist[e];
}

void init() {
	fastio;

	cin >> n >> m >> x;

	for (int i = 0; i < m; i++) {
		int s, e, t;
		cin >> s >> e >> t;
		adjlist[s].push_back({ e, t });
	}
}

int main() {
	init();

	for (int i = 1; i <= n; i++) {
		if (i != x) {
			iToX[i] = dijkstra(i, x);
		}
	}
	dijkstra(x, 0);

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		if (i != x) {
			ans = max(ans, dist[i] + iToX[i]);
		}
	}
	cout << ans;
}