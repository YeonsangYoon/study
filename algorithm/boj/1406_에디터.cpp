#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct node {
	char c;
	node* next, * prev;
};

int n, m, ptr = 0;
node head, tail;
node pool[1000000];
node* cursor;

node* get_node(char ch) {
	node* ret = &pool[ptr++];
	ret->c = ch;
	return ret;
}

void insert(char ch) {
	node* newNode = get_node(ch);
	node* tmp = cursor->prev;
	tmp->next = newNode;
	newNode->prev = tmp;
	newNode->next = cursor;
	cursor->prev = newNode;
}

void mode(int dir) {
	if (dir == 1) { // left

	}
}

void init() {
	head.next = &tail;
	head.prev = NULL;
	tail.next = NULL;
	tail.prev = &head;

	string s;
	cin >> s >> m;
	n = s.size();
}

int main(void) {
	fastio;
	init();


}