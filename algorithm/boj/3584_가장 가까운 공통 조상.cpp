/**********************************************************************
작성일 : 2022-3-05
문제 :
	LCA 구하는 문제
풀이 :
	기본적으로 LCA를 구현할 수 있는지 확인하는 문제 
	상대적으로 까다로운 알고리즘이다 보니 자주 리마인드하자
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define Pmax 20
#define MAX_SIZE 10001
using namespace std;

int n;	// tree 노드 수
int root;
int depth[MAX_SIZE];
int parent[MAX_SIZE][Pmax + 1];
vector<int> adjlist[MAX_SIZE];

void init() {
	memset(depth, 0, sizeof(depth));
	memset(parent, 0, sizeof(parent));

	cin >> n;
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
	}
	for (int i = 0; i < n - 1; i++) {
		int p, c;
		cin >> p >> c;
		adjlist[p].push_back(c);
		parent[c][0] = p;
	}

	root = 0;
	for (int i = 1; i <= n; i++) {
		if (parent[i][0] == 0)
			root = i;
	}

	queue<int> q;
	q.push(root);
	depth[root] = 1;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& child : adjlist[now]) {
			q.push(child);
			depth[child] = depth[now] + 1;
		}
	}

	for (int i = 1; (1 << i) <= n; i++) {
		for (int j = 1; j <= n; j++) {
			parent[j][i] = parent[parent[j][i - 1]][i - 1];
		}
	}
}
int lca() {
	int a, b;
	cin >> a >> b;

	if (depth[a] < depth[b]) swap(a, b);

	for (int i = Pmax; i >= 0; i--) {
		if (depth[a] - (1 << i) >= depth[b])
			a = parent[a][i];
	}

	if (a == b) return a;

	for (int i = Pmax; i >= 0; i--) {
		if (parent[a][i] != parent[b][i]) {
			a = parent[a][i];
			b = parent[b][i];
		}
	}
	return parent[a][0];
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		cout << lca() << '\n';
	}
}