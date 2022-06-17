/**********************************************************************
작성일 : 2022-6-17
문제 :
	양방향 그래프에서 한 정점 S에서 T로 이동하려 한다.
	이동할 때 T에 가까워지며 이동하는 경우, 이를 합리적인 이동이라한다.
	이때, 가능한 합리적인 이동경로의 개수를 구하라.
풀이 :
	한 정점에서 다른 정점으로 이동할 때 목적지에 가까워 지는지 확인하기 위하여
	모든 정점과 목적지와의 최단거리를 다익스트라를 통해 구하였다.

	또한, 이동 가능한 간선을 목적지까지의 최단거리 배열을 통해 식별한 뒤
	출발지에서 목적지까지 갈 수 있는 경로를 dfs로 구하였고, 메모이제이션을 통해
	dfs의 시간복잡도를 줄였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n, m;
int dp[1001], toEnd[1001];
bool visited[1001];
struct node {
	int u, dist;
	bool operator<(const node& a) const {
		return a.dist < dist;
	}
};
vector<node> adjlist[1001];

int get_valid_path(int cur) {
	if (cur == 2)
		return 1;
	else if (dp[cur])
		return dp[cur];

	for (node& edge : adjlist[cur]) {
		if (toEnd[cur] > toEnd[edge.u]) {
			visited[edge.u] = true;
			dp[cur] += get_valid_path(edge.u);
			visited[edge.u] = false;
		}
	}
	return dp[cur];
}

void dijkstra() {
	for (int i = 1; i <= n; i++) {
		toEnd[i] = INF;
	}
	toEnd[2] = 0;

	priority_queue<node> pq;
	pq.push({ 2, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (toEnd[now.u] < now.dist) continue;

		for (node& edge : adjlist[now.u]) {
			if (toEnd[edge.u] > toEnd[now.u] + edge.dist) {
				toEnd[edge.u] = toEnd[now.u] + edge.dist;
				pq.push({ edge.u, toEnd[edge.u] });
			}
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a].push_back({ b, c });
		adjlist[b].push_back({ a, c });
	}
}

int main(void) {
	fastio;
	init();
	dijkstra();

	visited[1] = true;
	cout << get_valid_path(1);
}