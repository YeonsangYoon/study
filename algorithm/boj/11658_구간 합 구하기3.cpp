/**********************************************************************
작성일 : 2022-7-18
문제 :
	N x N 배열의 구간합을 구하는 프로그램을 구하라.
	해당 프로그램은 m개의 쿼리를 수행하고, 쿼리는 배열의 수을 바꾸거나, 구간합을 구하는 것이다.
풀이 :
	2D Segment Tree를 구현해야만 해결할 수 있다.
	만약 1D Segment Tree를 사용하면 시간복잡도가 최악의 경우 O(mnlogn)이고, TLE가 발생한다.
	따라서 2D Segment Tree를 구현하여 시간복잡도를 O(mlognlogn)으로 최적화하였다.
	예상 공간복잡도는 O(n^2)이다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define S 1024

int n, m;
int segTree[2 * S][2 * S];

void update(int x, int y, int newNum) {
	int curX = S + x - 1;
	int curY = S + y - 1;
	int diff = newNum - segTree[curX][curY];

	while (curX > 0) {
		curY = S + y - 1;
		while (curY > 0) {
			segTree[curX][curY] += diff;
			curY /= 2;
		}
		curX /= 2;
	}
}

int queryCol(int y1, int y2, int l, int r, int cur, int row) {
	if (y1 > r || y2 < l) {
		return 0;
	}
	else if (y1 <= l && y2 >= r) {
		return segTree[row][cur];
	}
	int mid = (l + r) / 2;
	return queryCol(y1, y2, l, mid, cur * 2, row)
		+ queryCol(y1, y2, mid + 1, r, cur * 2 + 1, row);
}

int queryRow(int x1, int x2, int y1, int y2, int l, int r, int cur) {
	if (x1 > r || x2 < l) {
		return 0;
	}
	else if (x1 <= l && x2 >= r) {
		return queryCol(y1, y2, 1, S, 1, cur);
	}
	int mid = (l + r) / 2;
	return queryRow(x1, x2, y1, y2, l, mid, cur * 2)
		+ queryRow(x1, x2, y1, y2, mid + 1, r, cur * 2 + 1);
}

void init() {
	cin >> n >> m;
	for (int i = S; i < S + n; i++) {
		for (int j = S; j < S + n; j++) {
			cin >> segTree[i][j];
		}
		for (int j = S - 1; j > 0; j--) {
			segTree[i][j] = segTree[i][j * 2] + segTree[i][j * 2 + 1];
		}
	}
	for (int i = S - 1; i > 0; i--) {
		for (int j = S; j < S + n; j++) {
			segTree[i][j] = segTree[i * 2][j] + segTree[i * 2 + 1][j];
		}
		for (int j = S - 1; j > 0; j--) {
			segTree[i][j] = segTree[i][j * 2] + segTree[i][j * 2 + 1];
		}
	}
}

int main(void) {
	fastio;
	init();
	
	for (int i = 0; i < m; i++) {
		int type; cin >> type;
		
		if (type) {
			int x1, y1, x2, y2;
			cin >> x1 >> y1 >> x2 >> y2;
			cout << queryRow(x1, x2, y1, y2, 1, S, 1) << '\n';
		}
		else {
			int x, y, c;
			cin >> x >> y >> c;
			update(x, y, c);
		}
	}
}