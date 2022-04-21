/**********************************************************************
작성일 : 2022-04-21
문제 :
	2차원 배열의 지도에서 각 칸은 고유의 높이가 있다. 이 지도에서 이동할 때는
	높이가 높은 칸에서 낮은 칸으로 이동해야하는 규칙이 있다. 
	이때 (1, 1)에서 (m, n)으로 이동할 수 있는 경로의 개수를 구하라.
풀이 :
	dfs를 통해 경로의 개수를 구하고, 메모이제이션을 통해 계산량을 줄였다.
	visited 배열을 통해 한번 계산한 값을 확인하고 그 결과는 dp배열에 저장한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int m, n;
int Map[501][501];
int dp[501][501];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
bool visited[501][501];

int dfs(int r, int c) {
	if (r == m && c == n)
		return 1;
	else if (visited[r][c])
		return dp[r][c];

	visited[r][c] = true;

	for (int i = 0; i < 4; i++) {
		int nr = r + dr[i];
		int nc = c + dc[i];

		if (nr < 1 || nr > m || nc < 1 || nc > n)
			continue;
		else if (Map[r][c] <= Map[nr][nc])
			continue;

		dp[r][c] += dfs(nr, nc);
	}
	return dp[r][c];
}

void init() {
	cin >> m >> n;
	for (int i = 1; i <= m; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << dfs(1, 1);
}