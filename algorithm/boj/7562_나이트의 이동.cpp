#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct node {
	int r, c;
};

int n;
int sr, sc, er, ec;
int dr[8] = { 2, 1, -1, -2, -2, -1, 1, 2 };
int dc[8] = { 1, 2, 2, 1 ,-1, -2 , -2, -1 };
int board[301][301];
bool visited[301][301];

int solve() {
	queue<node> q;
	q.push({ sr, sc });
	visited[sr][sc] = true;

	while (!q.empty()) {
		node now = q.front(); q.pop();

		for (int i = 0; i < 8; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];

			if (nr < 0 || nr >= n || nc < 0 || nc >= n)
				continue;
			else if (visited[nr][nc])
				continue;
			board[nr][nc] = board[now.r][now.c] + 1;
			visited[nr][nc] = true;
			q.push({ nr, nc });
		}
	}
	return board[er][ec];
}

void init() {
	cin >> n;
	cin >> sr >> sc >> er >> ec;
	memset(board, 0, sizeof(board));
	memset(visited, false, sizeof(visited));
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		cout << solve() << '\n';
	}
}