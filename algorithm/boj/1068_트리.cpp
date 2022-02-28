/**********************************************************************
작성일 : 2022-2-28
문제 :
	트리가 주어지고 한개의 노드를 삭제할 때 변경된 트리의 리프노드 개수를 구하라
풀이 :
	연결리스트를 구현하고 이를 통해 dfs를 수행하여 리프의 개수를 구한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, root, cnt = 0;
int deleteNode;
vector<int> adjlist[51];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int parent; cin >> parent;
		if (parent != -1) {
			adjlist[parent].push_back(i);
		}
		else {
			root = i;
		}
	}
	cin >> deleteNode;
	adjlist[deleteNode].clear();
}
void dfs(int parent) {
	int sz = (int)adjlist[parent].size();
	if (sz == 0 || (sz == 1 && adjlist[parent][0] == deleteNode)) {
		if(parent != deleteNode)
			cnt++;
		return;
	}
	for (int& child : adjlist[parent]) {
		dfs(child);
	}
}

int main() {
	fastio;

	init();
	dfs(root);
	cout << cnt;
}