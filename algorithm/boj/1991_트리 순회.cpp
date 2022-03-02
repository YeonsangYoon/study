/**********************************************************************
작성일 : 2022-3-02
문제 :
	노드 데이터가 대문자 알파벳인 이진트리를 3가지 방법을 통해 순회하라
	(전위 순회, 중위 순회, 후위 순회)
풀이 :
	각 순회는 dfs를 통해 구현 가능하고 
	root, leftchild, rightchild의 방문 순서에 따라 달라진다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
struct child {
	char c;
	int left, right;
};
child adjlist[27];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		char p, c1, c2;
		cin >> p >> c1 >> c2;
		adjlist[p - 'A'].c = p;
		if (c1 != '.')
			adjlist[p - 'A'].left = c1 - 'A';
		else
			adjlist[p - 'A'].left = -1;
		if (c2 != '.')
			adjlist[p - 'A'].right = c2 - 'A';
		else
			adjlist[p - 'A'].right = -1;
	}
}
void pre_order(int parent) {
	cout << adjlist[parent].c;
	if (adjlist[parent].left != -1)
		pre_order(adjlist[parent].left);
	if (adjlist[parent].right != -1)
		pre_order(adjlist[parent].right);
}
void in_order(int parent) {
	if (adjlist[parent].left != -1)
		in_order(adjlist[parent].left);
	cout << adjlist[parent].c;
	if (adjlist[parent].right != -1)
		in_order(adjlist[parent].right);
}
void post_order(int parent) {
	if (adjlist[parent].left != -1)
		post_order(adjlist[parent].left);
	if (adjlist[parent].right != -1)
		post_order(adjlist[parent].right);
	cout << adjlist[parent].c;
}

int main() {
	fastio;

	init();

	pre_order(0); cout << '\n';
	in_order(0); cout << '\n';
	post_order(0); cout << '\n';
}