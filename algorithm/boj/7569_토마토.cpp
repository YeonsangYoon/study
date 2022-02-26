/**********************************************************************
작성일 : 2022-2-26
문제 :
	3차원으로 쌓을 수 있는 토마토 박스에 있는 토마토가 전부 익을 때까지 
	최소 며칠이 걸리는 지 구하라
	하루 지날때마다 익은 토마토 위, 아래, 왼쪽, 오른쪽, 앞, 뒤로 전이된다.
풀이 :
	bfs를 통해 총 며칠이 걸리는 지 계산한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n * m * h)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 101
using namespace std;

int n, m, h;
int box[MAX][MAX][MAX];
int dist[MAX][MAX][MAX];
bool visited[MAX][MAX][MAX];
int dr[6] = { 1, -1, 0, 0, 0, 0 };
int dc[6] = { 0, 0, 1, -1, 0, 0 };
int dh[6] = { 0, 0, 0, 0, 1, -1 };
struct pos {
	int r, c, h;
};

void init() {
	cin >> m >> n >> h;
	for (int k = 0; k < h; k++) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				cin >> box[i][j][k];
			}
		}
	}
	memset(dist, 0, sizeof(dist));
	memset(visited, false, sizeof(visited));
}
int solve() {
	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (box[i][j][k] == 1) {
					q.push({ i, j, k });
					visited[i][j][k] = true;
				}
			}
		}
	}
	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 6; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int nh = now.h + dh[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= m || nh < 0 || nh >= h)
				continue;
			else if (visited[nr][nc][nh] || box[nr][nc][nh] != 0)
				continue;

			visited[nr][nc][nh] = true;
			box[nr][nc][nh] = 1;
			dist[nr][nc][nh] = dist[now.r][now.c][now.h] + 1;
			q.push({ nr, nc, nh });
		}
	}

	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int k = 0; k < h; k++) {
				if (box[i][j][k] == 0) return -1;
				ret = max(ret, dist[i][j][k]);
			}
		}
	}
	return ret;
}

int main() {
	fastio;

	init();
	cout << solve();
}