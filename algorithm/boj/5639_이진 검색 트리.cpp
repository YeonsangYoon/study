/**********************************************************************
작성일 : 2022-1-31
문제 :
	이진 검색 트리를 전위순회한 결과를 통해 해당 트리의 후위 순회 결과를 구하라
풀이 :
	binary tree를 구현하고 전위순회의 결과를 토대로 노드를 insert해준다.
	이를 통해 전체 tree를 build해주고 다시 후위순회를 하여 결과를 출력함
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<int> ans;
struct node {
	int key = -1;
	node *left, *right;
};

node* insert(node *cur, int x) {
	if (cur == NULL) {
		cur = new node();
		cur->key = x;
	}
	else if (cur->key > x) {
		cur->left = insert(cur->left, x);
	}
	else {
		cur->right = insert(cur->right, x);
	}
	return cur;
}
node* build_tree() {
	int n;
	node* root = NULL;
	while (cin >> n) {
		root = insert(root, n);
	}
	return root;
}
void post_order(node* cur) {
	if (cur->left)
		post_order(cur->left);
	if (cur->right)
		post_order(cur->right);
	cout << cur->key << '\n';
}

int main() {
	fastio;

	node* tree = build_tree();
	post_order(tree);
}