/**********************************************************************
작성일 : 2022-04-05
문제 :
	5가지 종류의 cctv가 있고, 최대 8개의 cctv가 n x m 크기의 방에 있다.
	각 cctv는 90도씩 회전시킬 수 있다고 한다. 이때 안전지역의 최소 개수를 구하라.
풀이 :
	cctv는 최대 8개이고 각각 4가지 방향으로 설정할 수 있다.
	완전탐색 수행시 경우의 수는 총 4^8가지이며 각 경우당 8*8*4번 연산하기 때문에
	최악의 경우 1600만 연산한다. 
	
	따라서 완전탐색이 충분히 가능하기 때문에 dfs통해 구현하였다.

	각 cctv별 감시지역을 체크하는 방법이 다르기 때문에 한 방향만 체크하는 함수를 구현하고
	set_cctv 함수를 cctv 타입별로 호출하면서 구현하였다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, cnt;
int ans = INT_MAX;
int room[8][8];
int dr[4] = { -1, 0, 1, 0 };
int dc[4] = { 0, 1, 0, -1 };

struct pos {
	int r, c;
};
pos cctv[8];

void copyArr(int a[][8], int b[][8]) {
	for (int i = 0; i < 8; i++)
		for (int j = 0; j < 8; j++)
			a[i][j] = b[i][j];
}

void set_one_dir(int r, int c, int dir) {
	for (int i = 1;; i++) {
		int nr = r + i * dr[dir];
		int nc = c + i * dc[dir];

		if (nr < 0 || nr >= n || nc < 0 || nc >= m)
			break;
		else if (room[nr][nc] == 6)
			break;
		else if (room[nr][nc] > 0)
			continue;

		room[nr][nc] = -1;
	}
	return;
}

void set_cctv(int idx, int dir) {
	int r = cctv[idx].r;
	int c = cctv[idx].c;
	int type = room[r][c];

	if (type == 1) {
		set_one_dir(r, c, dir);
	}
	else if (type == 2) {
		set_one_dir(r, c, dir);
		set_one_dir(r, c, (dir + 2) % 4);
	}
	else if (type == 3) {
		set_one_dir(r, c, dir);
		set_one_dir(r, c, (dir + 1) % 4);
	}
	else if (type == 4) {
		set_one_dir(r, c, dir);
		set_one_dir(r, c, (dir + 1) % 4);
		set_one_dir(r, c, (dir + 3) % 4);
	}
	else if (type == 5) {
		set_one_dir(r, c, dir);
		set_one_dir(r, c, (dir + 1) % 4);
		set_one_dir(r, c, (dir + 2) % 4);
		set_one_dir(r, c, (dir + 3) % 4);
	}
}

void dfs(int cur) {
	if (cur == cnt) {
		int p = 0;
		for (int i = 0; i < n; i++)
			for (int j = 0; j < m; j++)
				if (room[i][j] == 0)
					p++;
		ans = min(ans, p);
		return;
	}

	int tmp[8][8];
	copyArr(tmp, room);

	for (int dir = 0; dir < 4; dir++) {
		set_cctv(cur, dir);
		dfs(cur + 1);
		copyArr(room, tmp);
	}
}

void init() {
	fastio;

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> room[i][j];
			if (room[i][j] >= 1 && room[i][j] <= 5) {
				cctv[cnt++] = { i, j };
			}
		}
	}
}

int main(void) {
	init();
	dfs(0);
	cout << ans;
}