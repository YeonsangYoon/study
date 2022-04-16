/**********************************************************************
작성일 : 2022-04-16
문제 :
	가족, 친척관계인 촌수를 계산하고자 한다. 
	n명의 가족들과 m개의 부모자식 관계가 주어질 때 주어지는 두 사람의 촌수를 계산하라.
풀이 :
	n명의 가족들은 부모 자식관계를 가지기 때문에 트리구조로 생각할 수 있다.
	이 때 두 명의 촌수는 해당 트리 내에서의 최단거리와 같다.

	dfs를 수행하여 해당 노드의 거리를 구하는 알고리즘을 구현하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int a, b;
bool visited[101];
vector<int> adjlist[101];

int dfs(int cur, int dist) {
	if (cur == b) {
		return dist;
	}

	int ret = INT_MAX;
	for (int next : adjlist[cur]) {
		if (!visited[next]) {
			visited[next] = true;
			ret = min(ret, dfs(next, dist + 1));
			visited[next] = false;
		}
	}
	return ret;
}

void init() {
	cin >> n >> a >> b;

	int m; cin >> m;
	for (int i = 0; i < m; i++) {
		int parent, child;
		cin >> parent >> child;
		adjlist[parent].push_back(child);
		adjlist[child].push_back(parent);
	}
}

int main(void) {
	fastio;
	init();

	visited[a] = true;
	int ans = dfs(a, 0);

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
}