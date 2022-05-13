/**********************************************************************
작성일 : 2022-05-07
문제 :
	2차원 격자모양 창고에 안익은 토마토와 익은 토마토가 보관되어 있다.
	만약 안익은 토마토가 익은 토마토와 인접하고 있으면 하루 뒤 익는다.
	이때, 창고 내 모든 토마토가 익는 데 최소 날짜를 구하라.
풀이 :
	2차원 배열에서 최단거리를 구하는 알고리즘과 같다.
	따라서 토마토가 익는 과정을 bfs로 구현할 수 있다.
	현재 토마토의 상태를 tomato배열에 저장하고, 
	언제 익었는 지에 대한 정보를 date배열에 저장한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int tomato[1001][1001];
int date[1001][1001];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0 , 0 };
struct pos {
	int r, c;
};

int change_tomato() {
	// 익은 토마토 queue에 적재
	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (tomato[i][j] == 1)
				q.push({ i, j });
		}
	}

	// bfs 수행(토마토 익히는 과정)
	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				continue;
			else if (tomato[nr][nc] != 0)
				continue;
			tomato[nr][nc] = 1;
			date[nr][nc] = date[now.r][now.c] + 1;
			q.push({ nr, nc });
		}
	}

	// 가장 나중에 익은 토마토 계산(만약 안익은 토마토 있으면 -1 리턴)
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			ret = max(ret, date[i][j]);
			if (tomato[i][j] == 0)
				return -1;
		}
	}
	return ret;
}

void init() {
	cin >> m >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> tomato[i][j];
		}
	}
}

int main(void) {
	fastio;
	init();
	
	cout << change_tomato();
}