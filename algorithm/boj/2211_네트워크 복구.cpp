/**********************************************************************
작성일 : 2022-3-04
문제 :
	네트워크에 해커가 침입했을 때 모든 회선을 차단하고 한 개의 슈퍼컴퓨터를 통해
	다시 복구한다.
	네트워크를 다시 복구하기 위해 슈퍼컴퓨터에서 다른 컴퓨터와 통신하기 위해 최소
	거리의 간선들만 선택하여 복구해야한다.
		1. 모든 컴퓨터가 통신 가능하도록 복구
		2. 슈퍼컴퓨터가 모든 컴퓨터와 통신하기 위한 최소 비용을 선택해야한다.
풀이 :
	이 문제는 단순히 최단거리를 구하는 것이 아니라 최단거리의 간선들을 모두 
	구해야한다.
	따라서 다익스트라를 통해 1과 연결된 모든 정점과의 최단거리를 모두 구하고
	bfs를 수행하면서 최단거리가 아닌 간선들을 골라낸다.
시간 제한 : 2초
메모리 제한 : 192MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1001
#define INF 100000000
using namespace std;

int n, m;
int dist[MAX_SIZE];
bool visited[MAX_SIZE];
struct node {
	int v;
	int d;
	bool isSelected = false;
	bool operator<(const node& a) const {
		return a.d < d;
	}
};
vector<node> adjlist[MAX_SIZE];

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b, c;
		cin >> a >> b >> c;
		adjlist[a].push_back({ b, c });
		adjlist[b].push_back({ a, c });
	}
	for (int i = 0; i < MAX_SIZE; i++) {
		dist[i] = INF;
	}
}
void dijkstra() {
	priority_queue<node> pq;
	pq.push({ 1, 0 });
	dist[1] = 0;

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		for (node& next : adjlist[now.v]) {
			if (now.d + next.d < dist[next.v]) {
				dist[next.v] = now.d + next.d;
				pq.push({ next.v, dist[next.v] });
			}
		}
	}
}
int find_valid_edge() {
	int cnt = 0;
	queue<node> q;
	q.push({ 1, 0 });
	visited[1] = true;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (node& next : adjlist[now.v]) {
			if (now.d + next.d == dist[next.v] && !visited[next.v]) {
				visited[next.v] = true;
				next.isSelected = true;
				q.push({ next.v, dist[next.v] });
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	fastio;

	init();
	dijkstra();
	
	cout << find_valid_edge() << '\n';
	for (int i = 1; i <= n; i++) {
		for (node& a : adjlist[i]) {
			if (a.isSelected) {
				cout << i << ' ' << a.v << '\n';
			}
		}
	}
}