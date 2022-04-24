/**********************************************************************
작성일 : 2022-04-24
문제 :
	n x n 크기를 가지는 토지가 있고, 각 격자의 높이가 주어진다.
	이때 비가 오면 잠기는 지역을 제외한 구역을 안전구역이라고 할 때 
	비 오는 양에 따른 안전구역의 최대개수를 구하라.
풀이 :
	bfs를 사용하여 안전구역의 개수를 사용하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int maxHeight;
int Map[101][101];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
bool check[101][101];
struct pos {
	int r, c;
};

int get_safety_zone(int rain) {
	memset(check, false, sizeof(check));

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (!check[i][j] && Map[i][j] > rain) {
				check[i][j] = true;
				cnt++;

				queue<pos> q;
				q.push({ i, j });

				while (!q.empty()) {
					pos now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 1 || nr > n || nc < 1 || nc > n)
							continue;
						else if (check[nr][nc] || Map[nr][nc] <= rain)
							continue;
						q.push({ nr, nc });
						check[nr][nc] = true;
					}
				}
			}
		}
	}
	return cnt;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> Map[i][j];
			maxHeight = max(maxHeight, Map[i][j]);
		}
	}
}

int main(void) {
	fastio;
	init();

	int maxCnt = 0;
	for (int rain = 0; rain <= maxHeight; rain++) {
		maxCnt = max(maxCnt, get_safety_zone(rain));
	}
	cout << maxCnt;
}