/**********************************************************************
작성일 : 2022-7-19
문제 :
	기본적인 구간합 문제, 수를 갱신하는 쿼리와 구간합을 구하는 쿼리를 수행해야한다.
풀이 :
	세그먼트 트리를 이용하여 구현하였다. 
	중간에 수가 갱신되기 때문에 누적합으로는 구할 수 있다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

int n, m, S = 1;
vector<ll> segTree;

void init() {
	cin >> n >> m;
	while (S < n)
		S <<= 1;
	segTree.resize(2 * S);
}

void update(int idx, int newNum) {
	int cur = S + idx - 1;
	int diff = newNum - segTree[cur];

	while (cur > 0) {
		segTree[cur] += diff;
		cur >>= 1;
	}
}

ll query(int ql, int qr, int l, int r, int cur) {
	if (ql > r || qr < l)
		return 0;
	else if (ql <= l && qr >= r)
		return segTree[cur];
	int mid = (l + r) / 2;
	return query(ql, qr, l, mid, cur * 2) + query(ql, qr, mid + 1, r, cur * 2 + 1);
}

int main(void) {
	fastio;
	init();

	for (int i = 0; i < m; i++) {
		int type; cin >> type;

		if (type) {
			int i, num;
			cin >> i >> num;
			update(i, num);
		}
		else {
			int i, j;
			cin >> i >> j;
			if (i > j) swap(i, j);
			cout << query(i, j, 1, S, 1) << '\n';
		}
	}
}