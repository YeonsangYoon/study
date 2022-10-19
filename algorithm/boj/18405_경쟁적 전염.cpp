#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int n, k;
int s, x, y;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
vector<vector<int>> tube;
vector<pos> virusList[1001];

void solve() {
	queue<pos> q;
	for (int i = 1; i <= k; i++) {
		for (pos& p : virusList[i])
			q.push(p);
	}

	for (int i = 0; i < s; i++) {
		int qcnt = q.size();
		for (int j = 0; j < qcnt; j++) {
			pos now = q.front(); q.pop();

			for (int k = 0; k < 4; k++) {
				int nr = now.r + dr[k];
				int nc = now.c + dc[k];

				if (nr < 0 || nr >= n || nc < 0 || nc >= n)
					continue;
				else if (tube[nr][nc])
					continue;
				q.push({ nr, nc });
				tube[nr][nc] = tube[now.r][now.c];
			}
		}
	}
}

void init() {
	cin >> n >> k;
	tube = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> tube[i][j];
			if (tube[i][j])
				virusList[tube[i][j]].push_back({ i,j });
		}
	}
	cin >> s >> x >> y;
}

int main(void) {
	fastio;
	init();
	solve();

	cout << tube[x - 1][y - 1];
}