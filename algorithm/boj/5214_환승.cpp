/**********************************************************************
작성일 : 2022-03-30
문제 :
	k개의 역이 연결되어 있는 하이퍼 튜브 n개가 있다. 1번역에서 n번역으로
	가기 위해 지나쳐야할 역의 최소 개수를 구하라.
풀이 :
	문제를 다른 말로 해석하면 환승역의 개수를 구하는 것이다.
	
	dummy node 개념을 적용하였다. 
	노선을 이동하면서 지나치는 역은 count하지 않기 때문에 각 노선의 dummy를 생성하고
	해당 노선의 역들과 연결하였다. 

	이렇게 인접리스트를 구성하고 bfs를 수행하여 거리를 구하였다.
	bfs를 수행하면서 dummy노드를 지나칠 때는 dist를 증가시키지 않았다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + mk)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k, m;
int dist[110000];
vector<int> adjlist[110000];

int bfs(int s, int e) {
	dist[s] = 1;

	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& nex : adjlist[now]) {
			if (dist[nex] == 0) {
				dist[nex] = (nex > n) ? dist[now] : dist[now] + 1;
				q.push(nex);
			}
		}
	}

	return (dist[e] == 0) ? -1 : dist[e];
}

void init() {
	fastio;

	cin >> n >> k >> m;
	for (int i = 1; i <= m; i++) {
		int ht = i + n;
		for (int j = 0; j < k; j++) {
			int st; cin >> st;
			adjlist[ht].push_back(st);
			adjlist[st].push_back(ht);
		}
	}
}

int main() {
	init();
	cout << bfs(1, n);
}