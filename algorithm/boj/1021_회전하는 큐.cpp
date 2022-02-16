/**********************************************************************
작성일 : 2022-2-16
문제 :
	n개의 노드가 있는 회전하는 큐에서 M개의 노드를 뽑으려고 할 때
	이동해야하는 최소 횟수를 구하라
풀이 :
	memory pool과 double linked list를 구현하여 문제를 해결하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <stdio.h>
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct node {
	int idx;
	node* next;
	node* prev;
};
int ptr = 0;
node pool[100];

node* get_node(int idx) {
	node* ret = &pool[ptr++];
	ret->idx = idx;
	return ret;
}
node* get_list(int n) {
	node* first = get_node(1);
	node* cur = first;
	for (int i = 2; i <= n; i++) {
		node* newNode = get_node(i);
		cur->next = newNode;
		newNode->prev = cur;
		cur = newNode;
	}
	first->prev = cur;
	cur->next = first;

	return first;
}
int solve(node* list, int size) {
	int ret = 0;
	int k; cin >> k;

	for (int i = 0; i < k; i++) {
		int idx; cin >> idx;
		int cnt = 0;
		while (1) {
			if (list->idx == idx)
				break;
			list = list->next;
			cnt++;
		}

		ret += min(cnt, size - cnt);
		size--;

		list->prev->next = list->next;
		list->next->prev = list->prev;
		list = list->next;
	}
	return ret;
}

int main() {
	fastio;

	int n; cin >> n;
	node* list = get_list(n);
	cout << solve(list, n);
}