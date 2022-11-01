#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct node {
	int num;
	node* next;
	node* prev;
};

int n, k, ptr;
node pool[1001];
node* cur;

node* get_node(int num) {
	node* ret = &pool[ptr++];
	ret->num = num;
	return ret;
}
void remove_cur_node() {
	node* p = cur->prev;
	node* n = cur->next;
	p->next = n;
	n->prev = p;
}

void init() {
	cin >> n >> k;
	cur = get_node(1);
	node* first = cur;
	for (int i = 2; i <= n; i++) {
		node* tmp = get_node(i);
		cur->next = tmp;
		tmp->prev = cur;
		cur = tmp;
	}
	cur->next = first;
	first->prev = cur;
}

int main(void) {
	fastio;
	init();

	vector<int> ans;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++)
			cur = cur->next;
		ans.push_back(cur->num);
		remove_cur_node();
	}

	cout << '<' << ans[0];
	for (int i = 1; i < n; i++)
		cout << ", " << ans[i];
	cout << '>';
}