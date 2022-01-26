/**********************************************************************
작성일 : 2022-1-26
문제 :
	이차원 배열에서 1을 가지는 영역의 개수를 구하라
풀이 :
	단순히 bfs, dfs를 구현하는것
	이번 문제에서 visited를 체크하는 위치에 따라 달라지는 것을 확인
	이것 때문에 조금 어렵게 느껴짐
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : ?
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int m, n;
int field[51][51];
int visited[51][51];
int dy[4] = { 0,0,1,-1 };
int dx[4] = { 1,-1,0,0 };
struct pos {
	int y, x;
};

void init() {
	memset(field, 0, sizeof(field));
	memset(visited, 0, sizeof(visited));

	cin >> m >> n;
	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		field[y][x] = 1;
	}
}
void bfs(int r, int c) {
	queue<pos> q;
	q.push({ r, c });
	visited[r][c] = 1;
	
	while (!q.empty()) {
		int y = q.front().y;
		int x = q.front().x;
		q.pop();

		for (int k = 0; k < 4; k++) {
			int ny = y + dy[k];
			int nx = x + dx[k];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			else if (visited[ny][nx] == 1 || field[ny][nx] == 0)
				continue;

			q.push({ ny,nx });
			visited[ny][nx] = 1;
		}
	}
}
int solve() {
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (field[i][j] == 1 && visited[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	fastio;
	
	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();
		cout << solve() << '\n';
	}
}