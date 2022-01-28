/**********************************************************************
작성일 : 2022-1-28
문제 :
	queue 구현 (push, pop, empty, size, front, back)
풀이 :
	양방향 linked list를 구현하고 queue에 맞는 method를 구현
시간 제한 : 1.5초
메모리 제한 : 128MB
예상 시간복잡도 : O(1)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct node {
	node* prev;
	node* next;
	int value;
};
node* head;
node* tail;

void Print(int x) { cout << x << '\n'; }
void init() {
	head = new node();
	tail = new node();

	head->prev = NULL;
	head->next = tail;
	head->value = 0;
	tail->prev = head;
	tail->next = NULL;
	tail->value = 0;
}
void push(int x) {
	node *newNode = new node();
	newNode->value = x;
	head->value++;
	
	node* tmp = tail->prev;
	newNode->next = tail;
	tail->prev = newNode;

	tmp->next = newNode;
	newNode->prev = tmp;
}
int pop() {
	if (head->value == 0) {
		return -1;
	}
	int ret = head->next->value;
	head->value--;

	node* top = head->next;
	head->next = top->next;
	top->next->prev = head;
	free(top);

	return ret;
}
int size() {
	return head->value;
}
int empty() {
	if (head->value) return 0;
	return 1;
}
int front() {
	if (head->value == 0)
		return -1;
	return head->next->value;
}
int back() {
	if (head->value == 0)
		return -1;
	return tail->prev->value;
}

int main() {
	fastio;

	init();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;

		if (s == "push") {
			int n; cin >> n;
			push(n);
		}
		else if (s == "pop") {
			Print(pop());
		}
		else if (s == "size") {
			Print(size());
		}
		else if (s == "empty") {
			Print(empty());
		}
		else if (s == "back") {
			Print(back());
		}
		else {
			Print(front());
		}
	}
}