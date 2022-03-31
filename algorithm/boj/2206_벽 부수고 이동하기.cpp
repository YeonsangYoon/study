/**********************************************************************
작성일 : 2022-03-31
문제 :
	n x m 크기의 맵에 이동할 수 없는 벽이 있다.
	이때 (1, 1)에서 출발하여 벽을 한개까지 부수고 (n, m)까지 이동한다.
	이때 최단거리를 구하고, 이동할 수 없으면 -1을 출력하라.
풀이 :
	행, 열, 벽을 부순 횟수 총 3가지 차원을 dp배열로 선언하고 이를 bfs로 순회하면서
	최단거리를 구했다.
시간 제한 : 2초
메모리 제한 : 192MB
예상 시간복잡도 : O(n*m)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int map[1001][1001];
int dp[1001][1001][2];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };

struct state {
	int r, c, cnt;
};

int solve() {
	dp[1][1][0] = 1;

	queue<state> q;
	q.push({ 1, 1, 0 });

	while (!q.empty()) {
		state now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			else if (map[nr][nc] == 1 && now.cnt == 1)
				continue;
			else if (map[nr][nc] == 1 && now.cnt == 0 && dp[nr][nc][1] == 0) {
				dp[nr][nc][1] = dp[now.r][now.c][0] + 1;
				q.push({ nr, nc, 1 });
			}
			else if (map[nr][nc] == 0 && dp[nr][nc][now.cnt] == 0) {
				dp[nr][nc][now.cnt] = dp[now.r][now.c][now.cnt] + 1;
				q.push({ nr, nc, now.cnt });
			}
		}
	}

	if (dp[n][m][0] == 0 && dp[n][m][1] == 0)
		return -1;
	else if (dp[n][m][0] == 0)
		return dp[n][m][1];
	else if (dp[n][m][1] == 0)
		return dp[n][m][0];
	else
		return min(dp[n][m][0], dp[n][m][1]);
}

void init() {
	fastio;

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			char c; cin >> c;
			map[i][j] = c - '0';
		}
	}
}

int main(void) {
	init();
	cout << solve();
}