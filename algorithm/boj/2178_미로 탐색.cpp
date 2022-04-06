/**********************************************************************
작성일 : 2022-04-06
문제 :
	n x m 크기의 격자모양 미로가 주어질 때 출발점(1, 1)에서 도착점(n, m)까지의 
	최단 거리를 구하라.
	미로내에서 1은 지나갈 수 있는 곳이고 0은 지나갈 수 없는 곳이다.
풀이 :
	격자모양 최단거리는 전형적인 bfs 문제이다. 
	이동하고자 하는 위치에 1이 있는 경우에만 큐에 push 하였다.
시간 제한 : 1초
메모리 제한 : 192MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int maze[110][110];

struct pos {
	int r, c;
};

int get_min_dist() {
	queue<pos> q;
	q.push({ 1, 1 });

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			else if (maze[nr][nc] != 1)
				continue;

			maze[nr][nc] = maze[now.r][now.c] + 1;
			q.push({ nr, nc });
		}
	}
	return maze[n][m];
}

void init() {
	fastio;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			maze[i][j] = c - '0';
		}
	}
}

int main(void) {
	init(); // 입력 및 초기화 함수
	cout << get_min_dist();
}