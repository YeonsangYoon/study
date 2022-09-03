#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int n, m;
int wolf, sheep;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
char area[251][251];
bool visited[251][251];

void solve() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && area[i][j] != '#') {
				int w = 0, s = 0;
				queue<pos> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pos now = q.front(); q.pop();
					if (area[now.r][now.c] == 'v') w++;
					else if (area[now.r][now.c] == 'k') s++;

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						else if (visited[nr][nc] || area[nr][nc] == '#')
							continue;

						visited[nr][nc] = true;
						q.push({ nr, nc });
					}
				}

				if (w >= s)
					wolf += w;
				else
					sheep += s;
			}
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> area[i][j];
		}
	}
	memset(visited, false, sizeof(visited));
}

int main(void) {
	fastio;
	init();
	solve();

	cout << sheep << ' ' << wolf;
}