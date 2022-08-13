#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int w, h;
int island[51][51];
bool visited[51][51];
int dr[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dc[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };

void init() {
	memset(visited, false, sizeof(visited));
	cin >> w >> h;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			cin >> island[i][j];
		}
	}
}

int solve() {
	int cnt = 0;

	for (int i = 1; i <= h; i++) {
		for (int j = 1; j <= w; j++) {
			if (!visited[i][j] && island[i][j]) {
				visited[i][j] = true;
				queue<pos> q;
				q.push({ i, j });

				while (!q.empty()) {
					pos now = q.front(); q.pop();

					for (int k = 0; k < 8; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr > h || nr < 1 || nc > w || nc < 1)
							continue;
						else if (visited[nr][nc] || island[nr][nc] == 0)
							continue;

						visited[nr][nc] = true;
						q.push({ nr, nr });
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main(void) {
	fastio;

	while (1) {
		init();
		if (w == 0 && h == 0) break;

		cout << solve() << '\n';
	}
}