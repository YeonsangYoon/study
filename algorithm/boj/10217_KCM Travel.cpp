/**********************************************************************
작성일 : 2022-3-16
문제 :
	N개의 공항과 K개의 티켓종류가 있을 때 1번 노드에서 N번 노드까지
	비용 M 이하로 갈 수 있는 방법 중 최단소요시간을 구하라.
풀이 :
	시작정점이 정해져있기 때문에 다익스트라를 사용하였다.
	다익스트라를 수행하면서 cost 정보를 함께 가지고 있으면서 cost가 m을
	초과하는 것에 대해 가지치기를 추가적으로 수행한다.
	또한, 다익스트라의 dp배열을 노드번호, cost를 가지고 있는 2차원 배열로
	선언했다. 
시간 제한 : 10초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n, m, k;
int rqTime[101][10001];
struct node {
	int v, cost, time;
	bool operator<(const node& a) const {
		return a.time < time;
	}
};
vector<node> adjlist[101];

int dijkstra() {
	rqTime[1][0] = 0;
	priority_queue<node> pq;
	pq.push({ 1, 0, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (rqTime[now.v][now.cost] < now.time)
			continue;
		for (node& edge : adjlist[now.v]) {
			int nextCost = now.cost + edge.cost;
			int nextTime = now.time + edge.time;

			if (nextCost > m || nextTime >= rqTime[edge.v][nextCost])
				continue;

			rqTime[edge.v][nextCost] = nextTime;
			pq.push({ edge.v, nextCost, nextTime });
		}
	}
	int ret = INF;
	for (int i = 0; i <= m; i++)
		ret = min(ret, rqTime[n][i]);
	return ret;
}

void init() {
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
		for (int j = 0; j <= m; j++)
			rqTime[i][j] = INF;
	}
	for (int i = 0; i < k; i++) {
		int u, v, cost, time;
		cin >> u >> v >> cost >> time;
		adjlist[u].push_back({ v, cost, time });
	}
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		int result = dijkstra();

		if (result == INF)
			cout << "Poor KCM\n";
		else
			cout << result << '\n';
	}
}