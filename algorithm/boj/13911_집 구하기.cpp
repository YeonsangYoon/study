/**********************************************************************
작성일 : 2022-3-15
문제 :
	n개의 정점과 m개의 간선이 있는 그래프에서 맥도날드, 스타벅스, 집 이렇게
	세 종류의 정점이 있다.
	이때 맥도날드, 스타벅스와의 거리가 각각의 기준보다 작음을 만족하는 최단거리를 구하라
풀이 :
	이 문제에서 dummy node라는 새로운 기법을 적용해보았다.
	dummy 노드란 실제 그래프에 존재하지 않지만, 알고리즘을 위해 임의로 생성하는 노드 이다.
	맥도날드, 스타벅스 각각 dummy노드를 생성하고 dijkstra를 수행한다.
	맥도날드 dummy 노드는 모든 맥도날드와 거리가 0인 단방향 간선이 있다. (dummy -> 맥날)
	스타벅스 또한 마찬가지이다.
	dijkstra를 이용하여 dummy에서 출발하여 모든 노드로 가는 최단거리를 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_NODE_SIZE 10003
using namespace std;

int n, m;
int macCond, starCond;
int macCnt, starCnt;
int macDummy, starDummy;
int macDist[MAX_NODE_SIZE], starDist[MAX_NODE_SIZE];
bool isMac[MAX_NODE_SIZE], isStar[MAX_NODE_SIZE];
vector<int> macList, starList;

struct node {
	int v, cost;
	bool operator<(const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adjlist[MAX_NODE_SIZE];

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v, w;
		cin >> u >> v >> w;
		adjlist[u].push_back({ v, w });
		adjlist[v].push_back({ u, w });
	}

	cin >> macCnt >> macCond;
	for (int i = 0; i < macCnt; i++) {
		int mac; cin >> mac;
		macList.push_back(mac);
		isMac[mac] = true;
	}

	cin >> starCnt >> starCond;
	for (int i = 0; i < starCnt; i++) {
		int star; cin >> star;
		starList.push_back(star);
		isStar[star] = true;
	}

	macDummy = 10001; starDummy = 10002;
	for (int& mac : macList) {
		adjlist[macDummy].push_back({ mac, 0 });
	}
	for (int& star : starList) {
		adjlist[starDummy].push_back({ star, 0 });
	}
}

int solve() {
	// mac
	for (int i = 1; i < MAX_NODE_SIZE; i++) {
		macDist[i] = INT_MAX;
	}
	macDist[macDummy] = 0;
	
	priority_queue<node> pq;
	pq.push({ macDummy, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		for (node& edge : adjlist[now.v]) {
			if (now.cost + edge.cost < macDist[edge.v]) {
				macDist[edge.v] = now.cost + edge.cost;
				pq.push({ edge.v, macDist[edge.v] });
			}
		}
	}

	// star
	for (int i = 1; i < MAX_NODE_SIZE; i++) {
		starDist[i] = INT_MAX;
	}
	starDist[starDummy] = 0;
	pq.push({ starDummy, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		for (node& edge : adjlist[now.v]) {
			if (now.cost + edge.cost < starDist[edge.v]) {
				starDist[edge.v] = now.cost + edge.cost;
				pq.push({ edge.v, starDist[edge.v] });
			}
		}
	}

	int dist = INT_MAX;
	for (int i = 1; i <= n; i++) {
		if (!isMac[i] && !isStar[i] && macDist[i] <= macCond && starDist[i] <= starCond) {
			dist = min(dist, macDist[i] + starDist[i]);
		}
	}
	return (dist == INT_MAX) ? -1 : dist;
}

int main() {
	fastio;

	init();
	cout << solve();
}