/**********************************************************************
작성일 : 2022-2-26
문제 :
	트리의 간선이 양방향으로 주어지고 루트를 알려줬을 때 트리를 만들고
	쿼리마다 주어진 노드를 루트로하는 서브트리의 노드 개수를 구하라
풀이 :
	백트레킹을 통해 각 노드의 parent와 그 노드를 루트로하는 서브트리의 노드 개수를 구한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
using namespace std;

int root;
int n, q;
int parent[MAX];
int cnt[MAX];
vector<int> adjlist[MAX];

void init() {
	cin >> n >> root >> q;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
}
int set_tree(int cur) {
	if ((int)adjlist[cur].size() == 1 && cur != root)
		return cnt[cur] = 1;

	cnt[cur] = 1;
	for (int& child : adjlist[cur]) {
		if (child == parent[cur]) continue;

		parent[child] = cur;
		cnt[cur] += set_tree(child);
	}
	return cnt[cur];
}

int main() {
	fastio;
	
	init();
	set_tree(root);

	for (int i = 0; i < q; i++) {
		int node; cin >> node;
		cout << cnt[node] << '\n';
	}
}