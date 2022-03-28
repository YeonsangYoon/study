/**********************************************************************
작성일 : 2022-03-28
문제 :
	여러 도시들의 그래프 관계가 주어진다. 출발지 s에서 미확인 도착지로 가는
	최단거리가 g, h를 잇는 도로를 포함하는 미확인 도착지만 오름차순으로 출력하라.
풀이 :
	출발지 s에서 미확인 도착지 i로 가는 최단거리에 g-h 간선이 포함되어 있는 지 확인하는
	방법은 다음과 같다. (dist(s, e) : s에서 e로 가는 최단거리)
	
	dist(s, i) = dist(s, g) + g-h + dist(h, i) or dist(s, h) + h-g + dist(g, i)

	최단거리는 다익스트라를 이용하여 구했고, 위 공식을 이용하여 알고리즘을 풀었다.
시간 제한 : 3초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n, m, t;
int s, g, h;
int gh;
int dist[2001];

vector<int> dst;
struct node {
	int v, dist;
	bool operator<(const node& a) const {
		return a.dist < dist;
	}
};
vector<node> adjlist[2001];

void dijkstra(int start) {
	for (int i = 1; i <= n; i++) dist[i] = INF;
	dist[start] = 0;

	priority_queue<node> pq;
	pq.push({ start, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (now.dist > dist[now.v]) continue;
		for (node& edge : adjlist[now.v]) {
			if (now.dist + edge.dist < dist[edge.v]) {
				dist[edge.v] = now.dist + edge.dist;
				pq.push({ edge.v, dist[edge.v] });
			}
		}
	}
}

void init() {
	cin >> n >> m >> t;
	cin >> s >> g >> h;

	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		adjlist[a].push_back({ b, d });
		adjlist[b].push_back({ a, d });

		if ((a == g && b == h) || (a == h && b == g))
			gh = d;
	}

	dst.clear();
	for (int i = 0; i < t; i++) {
		int x; cin >> x;
		dst.push_back(x);
	}
	sort(dst.begin(), dst.end());
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();

		dijkstra(s);
		int sToh = dist[h];
		int sTog = dist[g];

		for (int& i : dst) {
			dijkstra(i);
			int iTos = dist[s];
			int iToh = dist[h];
			int iTog = dist[g];

			if ((iTos == iToh + gh + sTog) || (iTos == iTog + gh + sToh)) {
				cout << i << ' ';
			}
		}
		cout << '\n';
	}
}