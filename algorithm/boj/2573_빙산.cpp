/**********************************************************************
작성일 : 2022-5-09
문제 :
	빙산이 2차원 배열에 위치하고 있고 각 격자의 칸에 빙산의 높이가 저장되어있다.
	빙산의 각 칸은 1년마다 바닷물과 접촉하고 있는 개수만큼 높이가 줄어든다.
	이때, 빙산이 두 조각으로 분리되는 최소의 시간을 구하라.
	만약, 빙산이 다 녹을 때까지 분리되지 않으면 0을 출력하라.
풀이 :
	빙산이 녹는 것은 반복문을 통해 구현하였고, 빙산 조각의 개수는 bfs를 통해 구현하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int iceberg[301][301];
bool visited[301][301];
bool isIceberg[301][301];
struct pos {
	int r, c;
};

int get_iceberg_cnt() {
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceberg[i][j] && !visited[i][j]) {
				queue<pos> q;

				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pos now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						else if (visited[nr][nc] || iceberg[nr][nc] == 0)
							continue;
						visited[nr][nc] = true;
						q.push({ nr, nc });
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

void melt_iceberg() {
	memset(isIceberg, false, sizeof(isIceberg));
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (iceberg[i][j]) isIceberg[i][j] = true;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!iceberg[i][j]) continue;

			for (int k = 0; k < 4; k++) {
				int nr = i + dr[k];
				int nc = j + dc[k];

				if (nr < 0 || nr >= n || nc < 0 || nc >= m)
					continue;
				else if (!isIceberg[nr][nc])
					iceberg[i][j] = max(iceberg[i][j] - 1, 0);
			}
		}
	}
}

int solve() {
	int cnt, year = 0;
	while (1) {
		cnt = get_iceberg_cnt();

		if (cnt > 1)
			return year;
		else if (cnt == 0) 
			return 0;

		melt_iceberg();
		year++;
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> iceberg[i][j];
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}