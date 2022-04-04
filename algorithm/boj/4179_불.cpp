/**********************************************************************
작성일 : 2022-04-04
문제 :
	n x m 크기의 격자모양 미로에서 탈출하려한다. 1분에 4방향으로 한칸씩
	불이 번진다고 할 때 탈출할 수 있는  최소 시간을 구하라. 
	만약 탈출하지 못한다면, IMPOSSIBLE을 출력하라.
		J - 출발 위치
		F - 불 위치
풀이 :
	미리 이동하기 전에 불의 경로를 구한다. 
	bfs를 통해 불이 번지는 위치를 maze 배열에 기록하고 각 위치별 번지는 시간을
	fire배열에 저장한다.

	그리고, 출발위치에서 가장자리로 탈출하는 경로를 bfs를 통하여 구한다.
	이때 이동하려는 장소가 불이 번지는 위치더라도 해당 불이 번지는 시간보다 일찍 도착하면
	이동 가능하다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int dist[1010][1010];
int fire[1010][1010];
char maze[1010][1010];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

struct pos {
	int r, c;
};
pos start;

int get_escape_time() {
	queue<pos> q;
	q.push(start);

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr == 0 || nr == n + 1 || nc == 0 || nc == m + 1)
				return dist[now.r][now.c] + 1;
			else if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			else if (dist[nr][nc] > 0)
				continue;
			else if (maze[nr][nc] == '#')
				continue;
			else if (maze[nr][nc] == 'F' && fire[nr][nc] <= dist[now.r][now.c] + 1)
				continue;

			dist[nr][nc] = dist[now.r][now.c] + 1;
			q.push({ nr, nc });
		}
	}

	return -1;
}

void set_fire() {
	queue<pos> q;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (maze[i][j] == 'F')
				q.push({ i, j });
		}
	}

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			else if (maze[nr][nc] == '#' || maze[nr][nc] == 'F')
				continue;

			maze[nr][nc] = 'F';
			fire[nr][nc] = fire[now.r][now.c] + 1;
			q.push({ nr, nc });
		}
	}
}

void init() {
	fastio;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> maze[i][j];
			if (maze[i][j] == 'J')
				start = { i, j };
		}
	}
}

int main(void) {
	init();
	set_fire();

	int result = get_escape_time();
	if (result == -1)
		cout << "IMPOSSIBLE";
	else
		cout << result;
}