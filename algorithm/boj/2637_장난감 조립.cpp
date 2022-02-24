/**********************************************************************
작성일 : 2022-2-24
문제 :
	기본부품과 중간부품과 완성부품이 있고 각 부품을 만들기 위한 관계가 주어질때
	완성부품을 만들기 위한 기본부품 각각의 필요 개수를 구하라
풀이 :
	각 부품들의 관계를 그래프로 표현한 뒤 이를 위상정렬을 수행하여 필요 개수를 구했다.
	만들어진 그래프는 단방향 그래프이다. => 위상정렬 수행 가능
	queue는 double linked list로 간단하게 구현했다. 
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 101
using namespace std;

int n, m;
int inDegree[MAX_N];
int outDegree[MAX_N];
int countArr[MAX_N];
struct edge {
	int v, cnt;
};
vector<edge> adjlist[MAX_N];

struct node {
	int data;
	node* next;
	node* prev;
};
node pool[MAX_N * MAX_N];
struct list {
	int ptr, sz;
	node *head;
	node *tail;

	void init() {
		ptr = sz = 0;
		head = get_node(0);
		tail = get_node(0);
		head->next = tail;
		tail->prev = head;
	}
	node* get_node(int data) {
		node* ret = &pool[ptr++];
		ret->data = data;
		ret->next = ret->prev = nullptr;
		return ret;
	}
	void push(int data) {
		node* newNode = get_node(data);
		node* tmp = tail->prev;
		tmp->next = newNode;
		newNode->prev = tmp;
		newNode->next = tail;
		tail->prev = newNode;
		sz++;
	}
	int pop() {
		if (sz <= 0) return -1;
		int ret = head->next->data;

		node* tmp = head->next->next;
		head->next = tmp;
		tmp->prev = head;
		sz--;
		return ret;
	}
};

void init() {
	cin >> n >> m;
	countArr[n] = 1;

	for (int i = 0; i < m; i++) {
		int x, y, cnt;
		cin >> x >> y >> cnt;
		adjlist[x].push_back({ y, cnt });
		inDegree[y]++;
		outDegree[x]++;
	}
}
void topological_sort() {
	list queue;
	queue.init();
	queue.push(n);

	while (queue.sz > 0) {
		int now = queue.pop();
		
		for (edge& e : adjlist[now]) {
			countArr[e.v] += (countArr[now] * e.cnt);
			if (--inDegree[e.v] == 0) {
				queue.push(e.v);
			}
		}
	}
}

int main() {
	fastio;

	init();
	topological_sort();

	for (int i = 1; i <= n; i++) {
		if (outDegree[i] == 0) {
			cout << i << ' ' << countArr[i] << '\n';
		}
	}
}