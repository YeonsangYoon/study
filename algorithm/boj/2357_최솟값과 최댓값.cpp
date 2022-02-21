/**********************************************************************
작성일 : 2022-2-21
문제 :
	구간의 최댓값 최솟값 구하는 문제
풀이 :
	N개의 원소를 가진 수열에서 구간의 최대, 최소값을 구하라
	seg tree를 구축하고 이를 통해 query를 logn에 수행한다.
시간 제한 : 2초
메모리 제한 : 192MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SEGTREE_SIZE 262144
#define MAX 1000000001
#define MIN 0
using namespace std;

int n, m;
int s;
struct node {
	int Min;
	int Max;
};
node segTree[MAX_SEGTREE_SIZE];

void init() {
	cin >> n >> m;
	
	s = n - 1;
	for (int i = 1; i < 32; i++) {
		s = s / 2;
		if (s == 0) {
			s = (1 << i);
			break;
		}
	}
	for (int i = s; i < 2 * s; i++) {
		if (i < s + n) {
			int num; cin >> num;
			segTree[i] = { num, num };
		}
		else {
			segTree[i] = { MAX, MIN };	// 선택되지 않도록 바꿔서 넣음
		}
	}
	for (int i = s - 1; i > 0; i--) {
		segTree[i].Min = min(segTree[2 * i].Min, segTree[2 * i + 1].Min);
		segTree[i].Max = max(segTree[2 * i].Max, segTree[2 * i + 1].Max);
	}
}
node query(int ql, int qr, int l, int r, int n) {
	if (ql > r || qr < l)
		return { MAX, MIN };
	else if (ql <= l && qr >= r)
		return segTree[n];

	int mid = (l + r) / 2;
	node left = query(ql, qr, l, mid, 2 * n);
	node right = query(ql, qr, mid + 1, r, 2 * n + 1);
	return { min(left.Min, right.Min), max(left.Max, right.Max) };
}

void solve() {
	for (int i = 0; i < m; i++) {
		int l, r;
		cin >> l >> r;
		node ret = query(l, r, 1, s, 1);
		cout << ret.Min << ' ' << ret.Max << '\n';
	}
}

int main() {
	fastio;

	init();
	solve();
}