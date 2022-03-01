/**********************************************************************
작성일 : 2022-3-01
문제 :
	기존 철도 노선이 있을 때 새로운 역을 추가하거나 폐쇄하는 공사를 수행하라.
풀이 :
	id를 배열의 인덱스로 사용하여 접근할 수 있는 line 배열을 선언하고,
	이를 linked list로 구현하였다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_STATION_ID 1000001
using namespace std;

int n, m;

struct station {
	int id;
	station* next;
	station* prev;
};
station line[MAX_STATION_ID];

station* get_node(int id) {
	line[id].id = id;
	line[id].next = NULL;
	line[id].prev = NULL;
	return &line[id];
}
int build_next(int id, int newId) {
	station* newNode = get_node(newId);
	station* tmp = line[id].next;

	line[id].next = newNode;
	newNode->prev = &line[id];
	tmp->prev = newNode;
	newNode->next = tmp;
	return tmp->id;
}
int build_prev(int id, int newId) {
	station* newNode = get_node(newId);
	station* tmp = line[id].prev;

	tmp->next = newNode;
	newNode->prev = tmp;
	newNode->next = &line[id];
	line[id].prev = newNode;
	return tmp->id;
}
int close_next(int id) {
	int ret = line[id].next->id;
	station* tmp = line[id].next->next;
	line[id].next = tmp;
	tmp->prev = &line[id];
	return ret;
}
int close_prev(int id) {
	int ret = line[id].prev->id;
	station* tmp = line[id].prev->prev;
	tmp->next = &line[id];
	line[id].prev = tmp;
	return ret;
}
void init() {
	cin >> n >> m;

	int id; cin >> id;
	station* first = get_node(id);
	first->next = first;
	first->prev = first;

	int prev = id;
	for (int i = 0; i < n - 1; i++) {
		cin >> id;
		build_next(prev, id);
		prev = id;
	}
}

int main() {
	fastio;

	init();
	for (int t = 0; t < m; t++) {
		string cmd; cin >> cmd;
		int i, j;
		int result = -1;

		if (cmd == "BN") {
			cin >> i >> j;
			result = build_next(i, j);
		}
		else if (cmd == "BP") {
			cin >> i >> j;
			result = build_prev(i, j);
		}
		else if (cmd == "CN") {
			cin >> i;
			result = close_next(i);
		}
		else if (cmd == "CP") {
			cin >> i;
			result = close_prev(i);
		}
		cout << result << '\n';
	}
}