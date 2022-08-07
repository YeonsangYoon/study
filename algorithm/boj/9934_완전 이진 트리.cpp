/**********************************************************************
작성일 : 2022-8-07
문제 :
	완전이진트리를 중위순회한 결과가 주어질 때, 해당 트리를 레벨별로 한줄씩 출력하라.
풀이 :
	분할 정복을 통해 tree를 일차원배열에 저장하였고, 레벨마다 한줄 씩 출력하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int k;
int tree[1024], order[1024];

void set_tree(int l, int r, int cur) {
	if (l > r) return;

	int mid = (l + r) / 2;
	tree[cur] = order[mid];

	set_tree(l, mid - 1, cur * 2);
	set_tree(mid + 1, r, cur * 2 + 1);
}

void init() {
	cin >> k;
	for (int i = 1; i < (1 << k); i++) {
		cin >> order[i];
	}
}

int main(void) {
	fastio;
	init();
	set_tree(1, (1 << k) - 1, 1);

	int ptr = 1;
	for (int i = 0; i < k; i++) {
		for (int j = 0; j < (1 << i); j++) {
			cout << tree[ptr++] << ' ';
		}
		cout << '\n';
	}
}