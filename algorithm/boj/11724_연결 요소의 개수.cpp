/**********************************************************************
작성일 : 2022-04-15
문제 :
	양방향 그래프가 주어졌을 때 해당 그래프에서 연결 요소의 개수를 구하라.
풀이 :
	dfs를 통해 각 연결요소를 탐색한다. dfs를 수행하면서 방문한 노드에 체크를 해준다.
	1 ~ n까지의 노드 중 아직 방문하지 않는 경우만 시작점으로 dfs를 수행한다.
	이때 dfs가 호출된 횟수가 연결요소의 개수이다.
시간 제한 : 3초
메모리 제한 : 512MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;	// n : 정점의 개수, m : 간선의 개수
bool visited[1001];	// 방문체크배열
vector<int> adjlist[1001];	// 인접리스트

void dfs(int curNode) {
	// 그래프 탐색
	visited[curNode] = true;

	for (int& next : adjlist[curNode]) {
		if (!visited[next])
			dfs(next);
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
}

int main(void) {
	fastio;
	init();

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			dfs(i);
			cnt++;
		}
	}
	cout << cnt;
}