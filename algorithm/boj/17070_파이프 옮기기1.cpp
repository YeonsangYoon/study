/**********************************************************************
작성일 : 2022-04-01
문제 :
	집이 n x n 크기의 격자모양을 가질때, 파이프의 끝을 (n,n)위치로 이동시키는
	방법의 수를 구하라.
풀이 :
	dp와 memo를 통해 간단하게 구현하였다.
	가로 -> 세로, 세로 -> 가로는 이동 불가하기 때문에 여러 상황에 대한
	예외처리에 신경써서 하였다. 
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int house[17][17];
int cnt[17][17][3];
int dr[3] = { 0, 1, 1 };
int dc[3] = { 1, 0, 1 };

int bfs() {
	cnt[1][2][0] = 1;

	for (int r = 1; r <= n; r++) {
		for (int c = 1; c <= n; c++) {
			for (int cDir = 0; cDir < 3; cDir++) {
				for (int nDir = 0; nDir < 3; nDir++) {
					if ((cDir == 0 && nDir == 1) || (cDir == 1 && nDir == 0))
						continue;

					int nr = r + dr[nDir];
					int nc = c + dc[nDir];

					if (nr > n || nc > n)
						continue;
					else if (house[nr][nc] == 1)
						continue;
					else if (nDir == 2 && (house[nr - 1][nc] == 1 || house[nr][nc - 1] == 1))
						continue;

					cnt[nr][nc][nDir] += cnt[r][c][cDir];
				}
			}
		}
	}

	return cnt[n][n][0] + cnt[n][n][1] + cnt[n][n][2];
}

void init() {
	fastio;

	cin >> n;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> house[i][j];
		}
	}
}

int main(void) {
	init();
	cout << bfs();
}