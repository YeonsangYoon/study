/**********************************************************************
작성일 : 2022-03-19
문제 :
	그래프와 시작점, 도착점이 주어질때 최단거리, 최단경로, 최단경로를 지나는
	노드의 개수를 구하라
풀이 :
	일반적인 다익스트라 구현과 달리 최단경로 자체를 구해야한다.
	
	다익스트라를 수행하면서 시작점에서 출발하여 임의의 노드까지 최단경로로 가기위해서
	방문한 바로 직전 노드를 parent배열에 기록한다.

	다익스트라를 수행한 뒤 parent에 기록되어있는 부모 노드를 이용하여,
	도착점에서 시작점까지 역추적하여 최단경로를 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O()
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int n, m;
int s, e;
int parent[1001];
ll dist[1001];
struct node {
	int v;
	ll cost;
	bool operator<(const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adjlist[1001];

ll dijkstra() {
	for (int i = 1; i <= n; i++) {
		dist[i] = LLONG_MAX;
	}
	dist[s] = 0;
	priority_queue<node> pq;
	pq.push({ s, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (now.cost > dist[now.v]) continue;
		for (node& edge : adjlist[now.v]) {
			if (dist[edge.v] > now.cost + edge.cost) {
				parent[edge.v] = now.v;
				dist[edge.v] = now.cost + edge.cost;
				pq.push({ edge.v, dist[edge.v] });
			}
		}
	}

	return dist[e];
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int s, e; ll cost;
		cin >> s >> e >> cost;
		adjlist[s].push_back({ e, cost });
	}
	cin >> s >> e;
}

int main() {
	fastio;

	init();
	ll minDist = dijkstra();

	int cur = e;
	stack<int> path;
	path.push(cur);

	while (cur != s) {
		path.push(parent[cur]);
		cur = parent[cur];
	}

	cout << minDist << '\n';
	cout << (int)path.size() << '\n';
	while (!path.empty()) {
		cout << path.top() << ' ';
		path.pop();
	}
}