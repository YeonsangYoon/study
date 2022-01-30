/**********************************************************************
작성일 : 2022-1-30
문제 :
	스택 구현
풀이 :
	linked list를 사용하여 stack을 구현
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct node {
	node* next;
	int value;
};
node* st;

void init() {
	st = new node();
	st->next = NULL;
	st->value = 0;
}
void push(int x) {
	node* newNode = new node();
	node* tmp = st->next;
	st->next = newNode;
	newNode->next = tmp;
	newNode->value = x;
	st->value++;
}
int pop() {
	if (st->value == 0) return -1;
	st->value--;
	int ret = st->next->value;
	node* tmp = st->next;
	st->next = st->next->next;
	free(tmp);
	return ret;
}
int size() {
	return st->value;
}
int empty() {
	return st->value ? 0 : 1;
}
int top() {
	if (st->value == 0) return -1;
	return st->next->value;
}

int main() {
	fastio;

	init();

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		string s; cin >> s;
		if (s == "push") {
			int x; cin >> x;
			push(x);
		}
		else if (s == "pop") {
			cout << pop() << '\n';
		}
		else if (s == "size") {
			cout << size() << '\n';
		}
		else if (s == "empty") {
			cout << empty() << '\n';
		}
		else if (s == "top") {
			cout << top() << '\n';
		}
	}
}