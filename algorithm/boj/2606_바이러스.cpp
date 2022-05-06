/**********************************************************************
작성일 : 2022-05-06
문제 :
	컴퓨터 네트워크가 주어지고, 1번 컴퓨터가 바이러스에 감염될 때 
	총 몇개의 컴퓨터가 추가로 바이러스에 감염되는지 구하라.
풀이 :
	1번 노드를 시작 정점으로 bfs를 수행하고, 방문한 노드의 개수를 센다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
bool visited[101];
vector<int> adjlist[101];

int bfs() {
	int cnt = 0;
	queue<int> q;
	
	q.push(1);
	visited[1] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now != 1) cnt++;

		for (int& next : adjlist[now]) {
			if (!visited[next]) {
				visited[next] = true;
				q.push(next);
			}
		}
	}
	return cnt;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
}

int main(void) {
	fastio;
	init();

	cout << bfs();
}