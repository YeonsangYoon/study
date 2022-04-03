/**********************************************************************
작성일 : 2022-04-03
문제 :
	연구소에 바이러스가 유출되었다. 이때 바이러스의 확산을 막기 위한
	벽을 3개 설치한다고 했을 때 얻을 수 있는 안전영역의 최대크기를 구하라.
풀이 :
	n, m의 최대 크기가 8이고 세우는 벽의 개수가 3개 뿐이기 때문에 완전탐색을 
	사용한다고 하더라도 연산의 크기가 크지 않다.
	총 64개의 격자중 3개를 선택하는 것이기 때문에 64 x 63 x 62 정도이다.
	또한 벽을 세운 다음 안전 영역을 구하는 것 역시 bfs를 통해 간단하게 해결가능하다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <algorithm>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int ans = 0;
int map[10][10];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
struct pos {
	int r, c;
};

int get_safe_zone() {
	int copyMap[10][10];
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			copyMap[i][j] = map[i][j];
		}
	}

	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (copyMap[i][j] == 2)
				q.push({ i, j });
		}
	}

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m)
				continue;
			else if (copyMap[nr][nc] == 1 || copyMap[nr][nc] == 2)
				continue;

			copyMap[nr][nc] = 2;
			q.push({ nr, nc });
		}
	}

	int cnt = 0;
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			if (copyMap[i][j] == 0)
				cnt++;
	return cnt;
}

void dfs(int cnt, int r, int c) {
	if (cnt == 3) {
		ans = max(ans, get_safe_zone());
		return;
	}

	for (int i = r * m + c; i < n * m; i++) {
		int nr = i / m;
		int nc = i % m;

		if (map[nr][nc] == 0) {
			map[nr][nc] = 1;
			dfs(cnt + 1, nr, nc);
			map[nr][nc] = 0;
		}
	}
}

void init() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> map[i][j];
		}
	}
}

int main(void) {
	init();

	dfs(0, 0, 0);
	cout << ans;
}