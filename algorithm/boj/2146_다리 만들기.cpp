/**********************************************************************
작성일 : 2022-2-13
문제 :
	여러 섬들 중 2개의 섬을 잇는 다리의 최단 거리를 구하라
풀이 :
	전형적인 bfs를 사용하는 문제 각 섬을 bfs를 통해 인덱싱하고
	전체 섬을 한칸씩 넓혀가면서 접촉하는 거리를 재면서 답을 구함
시간 제한 : 2초
메모리 제한 : 192MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <cstring>
#include <queue>
#include <limits.h>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };
int Map[101][101];
int islandId[101][101];
struct pos {
	int x, y;
};

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> Map[i][j];
		}
	}
}
void mark_island_id() {
	bool visited[101][101];
	memset(visited, false, sizeof(visited));

	int id = 1;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j] && Map[i][j] == 1) {
				queue<pos> q;
				q.push({j, i });
				visited[i][j] = true;
				islandId[i][j] = id++;

				while (!q.empty()) {
					pos now = q.front(); q.pop();
					
					for (int i = 0; i < 4; i++) {
						int ny = now.y + dy[i];
						int nx = now.x + dx[i];

						if (nx < 0 || nx >= n || ny < 0 || ny >= n)
							continue;
						else if (Map[ny][nx] == 0 || visited[ny][nx])
							continue;
						visited[ny][nx] = true;
						islandId[ny][nx] = islandId[now.y][now.x];
						q.push({ nx, ny });
					}
				}
			}
		}
	}
}
int get_min_bridge() {
	int ret = INT_MAX;
	queue<pos> q;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (Map[i][j] == 1) {
				q.push({ j, i });
			}
		}
	}

	while (!q.empty()) {
		pos now = q.front(); q.pop();

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= n)
				continue;
			else if (Map[ny][nx] == 0) {
				Map[ny][nx] = Map[now.y][now.x] + 1;
				q.push({ nx, ny });
				islandId[ny][nx] = islandId[now.y][now.x];
				continue;
			}
			else if (Map[ny][nx] >= 1) {
				if (islandId[ny][nx] != islandId[now.y][now.x]) {
					ret = min(ret, Map[ny][nx] + Map[now.y][now.x] - 2);
				}
			}
		}
	}
	return ret;
}

int main() {
	fastio;

	input();
	mark_island_id();
	cout << get_min_bridge();

	return 0;
}