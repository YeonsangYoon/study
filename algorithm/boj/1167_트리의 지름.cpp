/**********************************************************************
작성일 : 2022-3-11
문제 :
	트리의 지름이란, 트리에서 임의의 두 점 사이의 거리 중 가장 긴 것을 말한다. 
	트리의 지름을 구하는 프로그램을 작성하시오.
풀이 :
	트리의 지름을 구하는 방법은 다음과 같다.
		1. 임의의 노드 x에서 가장 먼 노드 y를 찾는다.
		2. y에서 가장 먼 노드 z를 찾는다.
		3. 트리의 지름은 y, z의 거리이다.
	이를 증명하는 것은 생략함
	가장 먼 노드를 찾는 것과 거리를 구하는 것은 dfs를 통해 구현하였다. 
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
#define INF 2000000000
using namespace std;

int n;
int dist[MAX_SIZE];
struct node {
	int v, cost;
	bool operator<(const node& a) const {
		return a.cost < cost;
	}
};
vector<node> adjlist[MAX_SIZE];

void dfs(int prev, int u, int cost) {
	dist[u] = cost;
	for (node& edge : adjlist[u]) {
		if (edge.v != prev) {
			dfs(u, edge.v, cost + edge.cost);
		}
	}
}

int get_farthest_node(int u) {
	dfs(0, u, 0);

	int ret = 1;
	for (int i = 1; i <= n; i++) {
		if (dist[i] > dist[ret]) {
			ret = i;
		}
	}
	return ret;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int u; cin >> u;
		while (1) {
			int v; cin >> v;
			if (v == -1) 
				break;
			int cost; cin >> cost;
			adjlist[u].push_back({ v, cost });
		}
	}
}

int main() {
	fastio;

	init();
	
	int x, y, z;
	x = 1;
	y = get_farthest_node(x);
	z = get_farthest_node(y);
	cout << dist[z];
}