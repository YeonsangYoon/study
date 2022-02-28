/**********************************************************************
작성일 : 2022-2-28
문제 :
	이진트리의 각 노드를 격자모양에 배치시킨다. 
	각 열에는 한개의 노드만 존재하고 각 노드는 depth와 width가 존재한다.
	이때 트리의 최대 넓이와 그 최대 넓이를 가지는 노드의 깊이를 구하라
풀이 :
	root, left-sub-tree, right-sub-tree를 구간으로 구분하여 분할정복을 수행하였다.
	root의 index를 미리 Index배열에 저장하여 시간복잡도를 줄였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_NODE 10001
using namespace std;

int n, maxDepth;
int leftSubTree[MAX_NODE];
int rightSubTree[MAX_NODE];
int leftNode[MAX_NODE];
int rightNode[MAX_NODE];
bool isRoot[MAX_NODE];
struct child {
	int left, right;
};
child adjlist[MAX_NODE];

int init() {
	memset(isRoot, true, sizeof(isRoot));
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int p, c1, c2;
		cin >> p >> c1 >> c2;
		adjlist[p] = { c1, c2 };

		if (c1 != -1)
			isRoot[c1] = false;
		if (c2 != -1)
			isRoot[c2] = false;
	}
	for (int i = 1; i < MAX_NODE; i++) {
		leftNode[i] = 100000000;
	}
	for (int i = 1; i <= n; i++) {
		if (isRoot[i])
			return i;
	}
}
int set_tree(int root) {
	if (adjlist[root].left != -1)
		leftSubTree[root] = set_tree(adjlist[root].left);
	if (adjlist[root].right != -1)
		rightSubTree[root] = set_tree(adjlist[root].right);
	return leftSubTree[root] + rightSubTree[root] + 1;
}
void set_width(int root, int l, int r, int depth) {
	int width = l + leftSubTree[root];
	leftNode[depth] = min(leftNode[depth], width);
	rightNode[depth] = max(rightNode[depth], width);
	maxDepth = max(maxDepth, depth);

	if (adjlist[root].left != -1)
		set_width(adjlist[root].left, l, width - 1, depth + 1);
	if (adjlist[root].right != -1)
		set_width(adjlist[root].right, width + 1, r, depth + 1);
}

int main() {
	fastio;

	int root = init();
	set_tree(root);
	set_width(root, 1, leftSubTree[1] + rightSubTree[1] + 1, 1);

	int w = 0;
	int maxWidth = 0;
	for (int i = 1; i <= maxDepth; i++) {
		int val = rightNode[i] - leftNode[i] + 1;
		if (maxWidth < val) {
			w = i;
			maxWidth = val;
		}
	}
	cout << w << ' ' << maxWidth;
}