/**********************************************************************
작성일 : 2022-03-22
문제 :
	그래프가 주어졌을 때 해당 그래프에서 트리가 몇개 있는 지 구하라.
	트리란 정점이 n개 간선이 n-1개 있고 임의의 두 정점에 대해 유일한 경로를 가진다.
풀이 :
	dfs를 통해 트리의 개수를 세고 사이클 여부를 검사한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
bool visited[501];
vector<int> adjlist[501];

bool dfs(int parent, int cur) {
	visited[cur] = true;

	int ret = true;
	for (int& child : adjlist[cur]) {
		if (!visited[child]) {
			ret &= dfs(cur, child);
		}
		else if (child != parent) {
			ret &= false;
		}
	}
	return ret;
}

int get_tree_count() {
	int cnt = 0;

	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			if (dfs(0, i))
				cnt++;
		}
	}

	return cnt;
}

void init() {
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int u, v;
		cin >> u >> v;
		adjlist[u].push_back(v);
		adjlist[v].push_back(u);
	}
}

int main() {
	fastio;

	for (int t = 1;; t++) {
		cin >> n >> m;

		if (n == 0 && m == 0) break;

		init();
		int result = get_tree_count();

		if (result == 0) {
			cout << "Case " << t << ": No trees.\n";
		}
		else if (result == 1) {
			cout << "Case " << t << ": There is one tree.\n";
		}
		else {
			cout << "Case " << t << ": A forest of " << result << " trees.\n";
		}
	}
}