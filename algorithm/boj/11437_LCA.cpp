/**********************************************************************
작성일 : 2022-08-04
작성자 : 윤연상
문제 :
	n개의 정점으로 이루어진 트리가 주어질 때, m개의 정점쌍의 최소공통조상을 구하라.
	2 ≤ N ≤ 50,000
	1 ≤ M ≤ 10,000
풀이 :
	정점과 쿼리의 개수가 적기 때문에 최적화 LCA를 사용하지 않고 나이브하게 구현해도 충분히 통과된다.
	두 정점에서 한칸 씩 올라가면서 LCA를 확인하는 방법으로 구현하였다.
시간 제한 : 3초
메모리 제한 : 256MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_VERTEX 50001

int n;
int parent[MAX_VERTEX], depth[MAX_VERTEX];
vector<int> adjlist[MAX_VERTEX];

int lca(int a, int b) {
	if (depth[a] < depth[b])
		swap(a, b);
	while (depth[a] > depth[b])
		a = parent[a];

	while (a != b) {
		a = parent[a];
		b = parent[b];
	}

	return a;
}

void dfs(int cur, int prev, int d) {
	depth[cur] = d;
	for (int& nex : adjlist[cur]) {
		if (nex != prev) {
			parent[nex] = cur;
			dfs(nex, cur, d + 1);
		}
	}
}

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
}

int main(void) {
	fastio;
	init();
	dfs(1, 0, 1);

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int a, b;
		cin >> a >> b;
		cout << lca(a, b) << '\n';
	}

	return 0;
}