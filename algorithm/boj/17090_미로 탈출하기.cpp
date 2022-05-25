/**********************************************************************
작성일 : 2022-5-25
문제 :
	각 칸에 다음 방향에 대한 문자가 적혀있는, 크기가 N x M인 미로가 있다.
	이때, 미로의 탈출 가능한 칸의 수를 구하라. (탈출 : 미로 경계 밖으로 이동)
풀이 :
	재귀호출을 통해 미로에서의 이동을 구현하였다.
	메모이제이션을 통해 불필요한 중복 연산을 줄였다. 
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };
int maze[501][501];		// 미로 
bool canOut[501][501];		// 탈출 가능 여부 
bool finished[501][501];	// 계산 완료
bool visited[501][501];		// 방문 체크(사이클 체크용)

bool dfs(int r, int c) {
	visited[r][c] = true;
	finished[r][c] = true;

	int nr = r + dr[maze[r][c]];
	int nc = c + dc[maze[r][c]];
	if (nr < 0 || nr >= n || nc < 0 || nc >= m) {
		canOut[r][c] = true;
		visited[r][c] = false;
		return true;
	}
	else if (finished[nr][nc]) {
		canOut[r][c] = canOut[nr][nc];
		visited[r][c] = false;
		return canOut[r][c];
	}
	else if (visited[nr][nc]) {
		canOut[r][c] = false;
		visited[r][c] = false;
		return false;
	}

	canOut[r][c] = dfs(nr, nc);
	visited[r][c] = false;
	return canOut[r][c];
}

int get_escape_count() {
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (!finished[i][j])
			dfs(i, j);

	int cnt = 0;
	for (int i = 0; i < n; i++) for (int j = 0; j < m; j++)
		if (canOut[i][j])
			cnt++;
	return cnt;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			if (c == 'U')
				maze[i][j] = 0;
			else if (c == 'R')
				maze[i][j] = 1;
			else if (c == 'D')
				maze[i][j] = 2;
			else if (c == 'L')
				maze[i][j] = 3;
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << get_escape_count();
}