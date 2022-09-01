#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int n, cnt;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int Map[26][26];
bool visited[26][26];

vector<int> solve() {
	vector<int> ret;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && Map[i][j]) {
				int mSize = 0;
				queue<pos> q;
				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pos now = q.front(); q.pop();
					mSize++;

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= n)
							continue;
						else if (Map[nr][nc] == 0 || visited[nr][nc])
							continue;

						q.push({ nr, nc });
						visited[nr][nc] = true;
					}
				}
				ret.push_back(mSize);
				cnt++;
			}
		}
	}
	sort(ret.begin(), ret.end());
	return ret;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char c; cin >> c;
			Map[i][j] = c - '0';
		}
	}
	memset(visited, false, sizeof(visited));
}

int main(void) {
	fastio;
	init();

	vector<int> result = solve();
	cout << cnt << '\n';

	for (int& i : result)
		cout << i << '\n';
}