/**********************************************************************
작성일 : 2022-2-19
문제 :
	주어진 수만큼 벽을 부술 수 있다고 할때 목적지까지의 최단거리를 구하라
풀이 :
	현재 좌표, 부순 벽의 수, 지나온 거리의 상태를 저장하고 이를 bfs로 구한다.
	visit 배열을 부순 벽의 수를 나타내는 차원을 증가시켜 3차원으로 표현해야한다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(n^2*k)
TEST 결과 : 통과
**********************************************************************/
#include <stdio.h>
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1001

using namespace std;

int n, m, k;
int map[MAX][MAX];
int visited[MAX][MAX][11];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

void input() {
	cin >> n >> m >> k;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		for (int j = 0; j < (int)s.size(); j++) {
			map[i][j] = s[j] - '0';
		}
	}
}

struct state {
	int r, c, k, dist;
};

int bfs() {
	int ret = 5000;

	queue<state> q;
	q.push({ 0, 0, 0, 1 });
	visited[0][0][0] = 1;

	while (!q.empty()) {
		state now = q.front(); q.pop();

		if (now.r == n - 1 && now.c == m - 1)
			return now.dist;

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				continue;

			if (map[nr][nc] == 0 && visited[nr][nc][now.k] == 0) {
				visited[nr][nc][now.k] = 1;
				q.push({ nr, nc, now.k, now.dist + 1 });
			}
			else if (map[nr][nc] == 1 && now.k < k && visited[nr][nc][now.k + 1] == 0) {
				visited[nr][nc][now.k + 1] = 1;
				q.push({ nr, nc, now.k + 1, now.dist + 1 });
			}
		}
	}
	return -1;
}

int main() {
	fastio;

	input();
	cout << bfs();

	return 0;
}