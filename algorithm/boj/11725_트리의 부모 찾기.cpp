/**********************************************************************
작성일 : 2022-1-20
문제 :
	주어진 그래프를 root가 1인 트리라고 했을 때 각 노드의 부모를 찾는 문제
풀이 :
	bfs, dfs 등을 통한 완전탐색을 수행하면서 각 노드의 부모를 찾는다.
	연결리스트를 이용하여 시간복잡도를 O(v+e)로 낮췄다.

	bfs, dfs를 모두 구현하였는데 이문제는 bfs가 훨씬 빨랐다. => 재귀 방식의 단점
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int parent[100001];
int visited[100001];
vector<int> adjlist[100001];

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
}
void bfs() {
	queue<int> q;
	q.push(1);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& nex : adjlist[now]) {
			if (visited[nex])
				continue;
			q.push(nex);
			visited[nex] = 1;
			parent[nex] = now;
		}
	}
}
void dfs(int cur, int p) {
	parent[cur] = p;

	for (int& child : adjlist[cur]) {
		if (visited[child])
			continue;

		visited[child] = 1;
		dfs(child, cur);
		visited[child] = 0;
	}
}

int main() {
	fastio;

	init();
	dfs(1, 0);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n';
	}
}