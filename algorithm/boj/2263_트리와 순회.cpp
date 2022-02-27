/**********************************************************************
작성일 : 2022-2-26
문제 :
	이진 트리의 in-order와 post-order가 주어졌을 때 pre-order를 구하라
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
#define MAX 100001
using namespace std;

int n, ptr = 0;
int Index[MAX];
int in[MAX], post[MAX], pre[MAX];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> in[i];
		Index[in[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> post[i];
	}
}
void get_preorder(int iL, int iR, int pL, int pR) {
	int root = post[pR];
	pre[ptr++] = root;

	if (iL >= iR || pL >= pR)
		return;

	int rootIdx = Index[root];
	
	if(rootIdx > iL)
		get_preorder(iL, rootIdx - 1, pL, pL + rootIdx - iL - 1);
	if(rootIdx < iR)
		get_preorder(rootIdx + 1, iR, pL + rootIdx - iL, pR - 1);
}

int main() {
	fastio;

	init();
	get_preorder(0, n - 1, 0, n - 1);

	for (int i = 0; i < n; i++) {
		cout << pre[i] << ' ';
	}
}