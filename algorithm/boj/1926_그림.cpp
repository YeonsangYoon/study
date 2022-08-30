#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int n, m, maxSize;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int paint[501][501];
bool visited[501][501];

int solve() {
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (paint[i][j] && !visited[i][j]) {
				int pSize = 0;
				queue<pos> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pos now = q.front(); q.pop();
					pSize++;

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						else if (paint[nr][nc] == 0 || visited[nr][nc])
							continue;

						q.push({ nr, nc });
						visited[nr][nc] = true;
					}
				}
				cnt++;
				maxSize = max(maxSize, pSize);
			}
		}
	}
	return cnt;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> paint[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
}

int main(void) {
	fastio;
	init();

	cout << solve() << '\n';
	cout << maxSize;
}