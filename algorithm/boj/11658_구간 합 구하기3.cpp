#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define S 1024

int n, m;
int segTree[S + 1][2 * S];

void update(int r, int c, int newNum) {
	int cur = S + c - 1;
	int diff = newNum - segTree[r][cur];

	while (cur > 0) {
		segTree[r][cur] += diff;
		cur /= 2;
	}
}

int query(int r, int qL, int qR, int left, int right, int cur) {
	if ((left < qL && right < qL) || (right > qR && left > qR)) {
		return 0;
	}
	else if (left >= qL && right <= qR) {
		return segTree[r][cur];
	}
	int mid = (left + right) / 2;
	int ret = 0;
	ret += query(r, qL, qR, left, mid, cur * 2);
	ret += query(r, qL, qR, mid + 1, right, cur * 2 + 1);
	return ret;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = S; j < S + n; j++) {
			cin >> segTree[i][j];
		}
	}
	for (int i = 1; i <= n; i++) {
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
			int r1, c1, r2, c2;
			cin >> r1 >> c1 >> r2 >> c2;
			
			int result = 0;
			for (int i = r1; i <= r2; i++) {
				result += query(i, c1, c2, 1, S, 1);
			}
			cout << result << '\n';
		}
		else {
			int r, c, newNum;
			cin >> r >> c >> newNum;
			update(r, c, newNum);
		}
	}
}