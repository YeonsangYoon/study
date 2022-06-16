#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 2000000000
using namespace std;

int n, m;
int toEnd[1001];
struct node {
	int u, dist;
	bool valid = true;
	bool operator<(const node& a) const {
		return a.dist < dist;
	}
};
vector<node> adjlist[1001];

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
}