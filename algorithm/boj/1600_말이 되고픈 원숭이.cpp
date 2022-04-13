/**********************************************************************
작성일 : 2022-04-13
문제 :
	k번의 말 이동을 할 수 있는 원숭이가 있다. 이 원숭이가 격자모양 세상을
	이동한다. (1, 1)에서 (n, m)으로 이동할 때 최단거리를 구하라.
풀이 :
	최단거리를 구하는 문제이기 때문에 bfs를 사용하였다. 
	말 이동방법은 최대 k번 사용할 수 있기 때문에 현재 상태에 대한 정보를 3차원으로 설정했다.
	
	현재 위치에서 이동할 수 있는 곳은 일반 이동 4개 말 이동 8개로 총 12가지 이다.
	이를 이용하여 dr, dc를 정의하고 bfs에 사용하였다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, k;
int world[201][201];
int dp[201][201][31];

// 0 ~ 3 : 일반 이동, 4 ~ 11 : 말 이동
int dr[12] = { 0, 0, 1, -1, 1, 1, -1, -1, 2, 2, -2, -2 };
int dc[12] = { 1, -1, 0, 0, 2, -2, 2, -2, 1, -1, 1, -1 };
struct state {
	int r, c, cnt;
};

int get_min_dist() {
	int ret = INT_MAX;

	queue<state> q;
	q.push({ 1, 1, 0 });

	while (!q.empty()) {
		state now = q.front(); q.pop();

		if (now.r == n && now.c == m)
			return dp[now.r][now.c][now.cnt];

		for (int i = 0; i < 12; i++) {
			if (now.cnt == k && i == 4) break;	// 말 이동방법 모두 사용시 말 이동은 제한

			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int newCnt = (i < 4) ? now.cnt : now.cnt + 1;	// 말 이동방법 사용시 cnt증가

			if (nr < 1 || nr > n || nc < 1 || nc > m)
				continue;
			else if (world[nr][nc] == 1 || dp[nr][nc][newCnt] != 0)
				continue;

			dp[nr][nc][newCnt] = dp[now.r][now.c][now.cnt] + 1;
			q.push({ nr, nc, newCnt });
		}
	}
	return -1;
}

void init() {
	cin >> k >> m >> n;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> world[i][j];
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << get_min_dist();
}