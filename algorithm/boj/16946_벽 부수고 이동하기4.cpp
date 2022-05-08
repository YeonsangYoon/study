/**********************************************************************
작성일 : 2022-5-08
문제 :
	N x M 격자모양의 맵이 주어진다. 맵은 0과 1로 이루어져있다.
	이때 각각의 벽에 대하여 해당 벽을 부수고 그 위치에서 이동할 수 있는 칸의 
	개수를 세어 맵과 같은 모양으로 출력하라.
풀이 :
	bfs를 이용하여 각각 0으로 이루어진 area의 번호와 그 개수를 구한다.
	그 후, 각 벽에 대하여 동서남북에 위치한 area의 개수를 더해 답을 구한다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(nm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int Map[1001][1001];
int area[1001][1001];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
bool visited[1001][1001];
map<int, int> areaCnt;
struct pos {
	int r, c;
};

void set_area() {
	int ptr = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visited[i][j] && Map[i][j] == 0) {
				int cnt = 0;
				queue<pos> q;

				q.push({ i, j });
				visited[i][j] = true;

				while (!q.empty()) {
					pos now = q.front(); q.pop();
					area[now.r][now.c] = ptr;
					cnt++;

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						else if (visited[nr][nc] || Map[nr][nc])
							continue;
						visited[nr][nc] = true;
						q.push({ nr, nc });
					}
				}
				areaCnt[ptr++] = cnt;
			}
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			char c; cin >> c;
			Map[i][j] = c - '0';
		}
	}
}

int main(void) {
	fastio;
	init();
	set_area();

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (Map[i][j]) {
				set<int> s;
				for (int k = 0; k < 4; k++) {
					int nr = i + dr[k];
					int nc = j + dc[k];
					if (nr < 0 || nr >= n || nc < 0 || nc >= m)
						continue;
					else if (Map[nr][nc])
						continue;
					s.insert(area[nr][nc]);
				}

				int ret = 1;
				for (auto a = s.begin(); a != s.end(); a++) {
					ret += areaCnt[*a];
				}
				cout << ret % 10;
			}
			else {
				cout << 0;
			}
		}
		cout << '\n';
	}
}