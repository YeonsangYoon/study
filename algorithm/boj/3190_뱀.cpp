/**********************************************************************
작성일 : 2022-2-15
문제 :
	뱀이 board안을 돌아다닌다. 
	움직이는 방향에 대한 정보가 주어졌을 때 언제 뱀이 멈추는 지 구하라.
풀이 :
	memory pool과 linked list를 구현하여 문제를 해결하였다.
	double linked list로 뱀을 구현하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <stdio.h>
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int board[101][101];
char dirInfo[10001];

struct node {
	int r, c;
	node* next;
	node* prev;
};
int ptr = 0;
node pool[10001];
node head, tail;

node* get_node(int r, int c) {
	node* ret = &pool[ptr++];
	ret->r = r; ret->c = c;
	return ret;
}
void input() {
	cin >> n;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		board[r][c] = 1;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int a; cin >> a;
		cin >> dirInfo[a];
	}
}
void init() {
	node* newNode = get_node(1, 1);

	head.next = newNode;
	head.prev = NULL;
	newNode->next = &tail;
	newNode->prev = &head;
	tail.next = NULL;
	tail.prev = newNode;

	board[1][1] = -1;
}
int solve() {
	int time = 1;
	int dir = 1;

	init();
	while (1) {
		int r = head.next->r; int c = head.next->c;
		int nr = r + dr[dir]; int nc = c + dc[dir];

		if (nr < 1 || nr > n || nc < 1 || nc > n)
			return time;
		else if (board[nr][nc] == -1)
			return time;

		node* newNode = get_node(nr, nc);
		node* tmp = head.next;
		head.next = newNode;
		newNode->prev = &head;
		newNode->next = tmp;
		tmp->prev = newNode;

		if (board[nr][nc] == 0) {
			tmp = tail.prev;
			tail.prev->prev->next = &tail;
			tail.prev = tail.prev->prev;
			board[tmp->r][tmp->c] = 0;
		}

		if (dirInfo[time] == 'D')
			dir = (dir + 1) % 4;
		else if (dirInfo[time] == 'L')
			dir = (dir + 3) % 4;

		r = nr; c = nc;
		board[nr][nc] = -1;
		time++;
	}
}

int main() {
	fastio;

	input();
	cout << solve();
}