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
	node* tmp = cursor->next;
	cursor->next = newNode;
	newNode->prev = cursor;
	newNode->next = tmp;
	tmp->prev = newNode;
	cursor = newNode;
}

void move_node(int dir) {
	if (dir == 1 && cursor->prev) // left
		cursor = cursor->prev;
	else if (dir == -1 && cursor->next->next) // right
		cursor = cursor->next;
}

void delete_node() {
	if (cursor != &head) {
		node* p = cursor->prev;
		node* n = cursor->next;
		p->next = n;
		n->prev = p;
		cursor = p;
	}
}

void init() {
	head.next = &tail;
	head.prev = NULL;
	tail.next = NULL;
	tail.prev = &head;
	cursor = &head;

	string s;
	cin >> s >> m;
	n = s.size();
	for (int i = 0; i < n; i++) {
		insert(s[i]);
	}
}

void print_node() {
	node* cur = head.next;
	while (cur->next) {
		cout << cur->c;
		cur = cur->next;
	}
}

int main(void) {
	fastio;
	init();

	for (int i = 0; i < m; i++) {
		char op;
		cin >> op;

		if (op == 'P') {
			char ch; cin >> ch;
			insert(ch);
		}
		else if (op == 'L') {
			move_node(1);
		}
		else if (op == 'D') {
			move_node(-1);
		}
		else if (op == 'B') {
			delete_node();
		}
	}

	print_node();
}