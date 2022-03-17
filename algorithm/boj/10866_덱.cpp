/**********************************************************************
작성일 : 2022-03-17
문제 :
	deque 구현
풀이 :
	double linked list로 구현함
시간 제한 : 0.5초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct node {
	int data;
	node* next;
	node* prev;
};
int ptr = 0;
node pool[10010];

node* get_node(int data) {
	pool[ptr] = { data, NULL, NULL };
	return &pool[ptr++];
}

struct DEQUE {
	int sz;
	node* head;
	node* tail;

	void init() {
		sz = 0; ptr = 0;
		head = get_node(-1);
		tail = get_node(-1);
		head->next = tail;
		tail->prev = head;
	}
	void push_back(int data) {
		node* newNode = get_node(data);
		node* tmp = tail->prev;

		tmp->next = newNode;
		newNode->prev = tmp;
		newNode->next = tail;
		tail->prev = newNode;
		sz++;
	}
	void push_front(int data) {
		node* newNode = get_node(data);
		node* tmp = head->next;

		head->next = newNode;
		newNode->prev = head;
		newNode->next = tmp;
		tmp->prev = newNode;
		sz++;
	}
	int pop_back() {
		if (sz <= 0) return -1;

		node* ret = tail->prev;
		node* tmp = tail->prev->prev;
		tmp->next = tail;
		tail->prev = tmp;
		sz--;
		return ret->data;
	}
	int pop_front() {
		if (sz <= 0) return -1;

		node* ret = head->next;
		node* tmp = head->next->next;
		head->next = tmp;
		tmp->prev = head;
		sz--;
		return ret->data;
	}
	int size() {
		return sz;
	}
	int empty() {
		return (sz > 0) ? 0 : 1;
	}
	int front() {
		if (sz <= 0) return -1;
		return head->next->data;
	}
	int back() {
		if (sz <= 0) return -1;
		return tail->prev->data;
	}
};
DEQUE dq;

int main() {
	fastio;

	dq.init();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string cmd; cin >> cmd;

		if (cmd == "push_back") {
			int data; cin >> data;
			dq.push_back(data);
		}
		else if (cmd == "push_front") {
			int data; cin >> data;
			dq.push_front(data);
		}
		else if (cmd == "pop_front") {
			cout << dq.pop_front() << '\n';
		}
		else if (cmd == "pop_back") {
			cout << dq.pop_back() << '\n';
		}
		else if (cmd == "size") {
			cout << dq.size() << '\n';
		}
		else if (cmd == "empty") {
			cout << dq.empty() << '\n';
		}
		else if (cmd == "front") {
			cout << dq.front() << '\n';
		}
		else if (cmd == "back") {
			cout << dq.back() << '\n';
		}
	}
}