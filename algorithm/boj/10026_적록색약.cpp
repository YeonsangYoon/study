/**********************************************************************
작성일 : 2022-3-13
문제 :
	빨간색과 초록색을 구분하지 못하는 적록색약과 일반인이 그림의 색깔 구역을
	볼 때 
풀이 :
	색약용 그림을 따로 만들어 각각 bfs를 수행한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0)
#define MAX_SIZE 101
using namespace std;

int n;
bool visited[MAX_SIZE][MAX_SIZE];
char normal[MAX_SIZE][MAX_SIZE];
char blind[MAX_SIZE][MAX_SIZE];
struct pos {
	int y, x;
};
int dy[4] = { 0, 0, 1, -1 };
int dx[4] = { 1, -1, 0, 0 };

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			char color; cin >> color;
			normal[i][j] = color;
			blind[i][j] = (color == 'G') ? 'R' : color;
		}
	}
}

int count_sector(char picture[][MAX_SIZE]) {
	memset(visited, false, sizeof(visited));

	int cnt = 0;
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (!visited[i][j]) {
				visited[i][j] = true;
				queue<pos> q;
				q.push({ i, j });

				while (!q.empty()) {
					pos now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int ny = now.y + dy[k];
						int nx = now.x + dx[k];

						if (ny >= n || ny < 0 || nx >= n || nx < 0)
							continue;
						else if (visited[ny][nx] || picture[ny][nx] != picture[now.y][now.x])
							continue;

						visited[ny][nx] = true;
						q.push({ ny, nx });
					}
				}
				cnt++;
			}
		}
	}
	return cnt;
}

int main() {
	fastio;

	init();

	cout << count_sector(normal) << ' ';
	cout << count_sector(blind);
}