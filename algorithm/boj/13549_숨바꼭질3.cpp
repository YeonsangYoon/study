/**********************************************************************
작성일 : 2022-7-16
문제 :
	수빈이는 점 n에 있고, 동생은 k에 있다. 이때, 수빈이는 걷거나 순간이동을 할 수 있다.
		- 걷기 : 1초 후에 +1이나 -1로 이동
		- 순간이동 : 0초 후에 x2로 이동
	위의 2가지 이동방법을 통해 동생을 찾을 수 있는 가장 빠른 시간을 구하라.
풀이 :
	다익스트라를 이용하여 최단거리를 구하였다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 100000
#define INF 1000000000

struct node {
	int n, time;
	bool operator<(const node& a) const {
		return a.time < time;
	}
};

int s, e;
int dist[MAX + 1];
priority_queue<node> pq;

int dijkstra() {
	pq.push({ s, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dist[now.n] < now.time) continue;

		if (now.n + 1 <= MAX) {
			if (dist[now.n + 1] > now.time + 1) {
				dist[now.n + 1] = now.time + 1;
				pq.push({ now.n + 1, now.time + 1 });
			}
		}
		if (now.n - 1 >= 0) {
			if (dist[now.n - 1] > now.time + 1) {
				dist[now.n - 1] = now.time + 1;
				pq.push({ now.n - 1, now.time + 1 });
			}
		}
		if (now.n * 2 <= MAX) {
			if (dist[now.n * 2] > now.time) {
				dist[now.n * 2] = now.time;
				pq.push({ now.n * 2, now.time });
			}
		}
	}

	return dist[e];
}

void init() {
	cin >> s >> e;
	for (int i = 0; i <= MAX; i++) {
		dist[i] = INF;
	}
	dist[s] = 0;
}

int main(void) {
	fastio;
	init();

	cout << dijkstra();
}