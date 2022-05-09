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

int solve() {
	int year = 0;
	while (1) {
		int cnt = get_iceberg_cnt();
		if (cnt > 1) break;
		else if (cnt == 0) return 0;

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
		year++;
	}
	return year;
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