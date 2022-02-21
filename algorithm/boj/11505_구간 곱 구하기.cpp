/**********************************************************************
작성일 : 2022-2-21
문제 :
	구간 곱 구하기
풀이 :
	N개의 원소를 가진 수열의 구간 곱을 구하는 문제
	원소가 계속 update되는 쿼리형 문제
	세그먼트 트리를 활용하여 update와 query를 모두 O(logn)에 수행하도록 구현
	- 원소 개수 N : 1 ~ 1,000,000
	- update 횟수 : 1 ~ 10,000
	- query 횟수 : 1 ~ 10,000
	update와 query 횟수가 거의 비슷함 => 세그트리가 유리함
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(N*L)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define SEGTREE_MAX_SIZE 2097152
#define MOD_NUM 1000000007
using namespace std;
typedef long long ll;

int n, m, k;
int s;
ll tree[SEGTREE_MAX_SIZE];

void init() {
	cin >> n >> m >> k;
	
	s = n - 1;
	for (int i = 1; i < 32; i++) {
		s = s / 2;
		if (s == 0) {
			s = (1 << i);
			break;
		}
	}
	
	for (int i = 0; i < 2 * s; i++) {
		tree[i] = 1;
	}
	for (int i = s; i < s + n; i++) {
		cin >> tree[i];
	}
	for (int i = s - 1; i > 0; i--) {
		tree[i] = (tree[i * 2] * tree[i * 2 + 1]) % MOD_NUM;
	}
}

void update(int idx, int data) {
	// bottom-up 방식
	idx = idx + s - 1;

	if (tree[idx] == data) return;

	tree[idx] = data;
	idx = idx / 2;
	while (idx > 0) {
		tree[idx] = (tree[idx * 2] * tree[idx * 2 + 1]) % MOD_NUM;
		idx = idx / 2;
	}
}

ll query(int ql, int qr, int l, int r, int node) {
	// top-down 방식
	if (r < ql || l > qr)
		return 1;
	else if (l >= ql && r <= qr)
		return tree[node];

	int mid = (l + r) / 2;
	return (query(ql, qr, l, mid, node * 2) * query(ql, qr, mid + 1, r, node * 2 + 1)) % MOD_NUM;
}

void solve() {
	int op, a, b;
	for (int i = 0; i < m + k; i++) {
		cin >> op >> a >> b;
		if (op == 1) {
			update(a, b);
		}
		else if (op == 2) {
			cout << query(a, b, 1, s, 1) << '\n';
		}
	}
}

int main() {
	fastio;

	init();
	solve();
}