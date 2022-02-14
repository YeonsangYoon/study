/**********************************************************************
작성일 : 2022-2-14
문제 :
	풍선을 터트리면서 그 안의 숫자를 순서대로 출력한다.
	터트린 풍선안에 적혀있는 숫자만큼 이동한다.
풀이 :
	memory pool과 linked list를 구현하여 문제를 해결하였다.
	linked list는 순환 double list로 구현함.
시간 제한 : 2초
메모리 제한 : 4MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <stdio.h>
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;

struct node {
	int idx, num;
	node* next;
	node* prev;
};
int ptr;
node pool[1001];

node* get_node(int idx, int num) {
	node* ret = &pool[ptr++];
	ret->idx = idx;
	ret->num = num;
	return ret;
}
node* make_list() {
	cin >> n;

	int num; cin >> num;
	node* first = get_node(1, num);
	
	node* cur = first;
	for (int i = 2; i <= n; i++) {
		cin >> num;
		node* newNode = get_node(i, num);
		cur->next = newNode;
		newNode->prev = cur;
		cur = cur->next;
	}
	cur->next = first;
	first->prev = cur;
	return first;
}
void print_order(node* cur) {
	int cnt = n;
	for (int i = 0; i < n; i++) {
		cout << cur->idx << ' ';

		int num = cur->num;
		bool dir = true;
		if (num > 0) {
			node* tmp = cur->next;
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			cur = tmp;
		}
		else {
			node* tmp = cur->prev;
			cur->next->prev = cur->prev;
			cur->prev->next = cur->next;
			cur = tmp;
			num = -num;
			dir = false;
		}

		for (int i = 0; i < num - 1; i++) {
			if (dir)
				cur = cur->next;
			else
				cur = cur->prev;
		}
	}
}

int main() {
	fastio;

	node* first = make_list();
	print_order(first);

	return 0;
}