/**********************************************************************
작성일 : 2022-07-23
작성자 : 윤연상
문제 :
	n개의 막대가 있는 히스토그램이 있다.
	이때, 히스토그램안에 있는 가장 큰 직사각형의 크기를 찾아라.
풀이 :
	divide ans conquer 방식을 사용하였다.
	현재 범위 내의 가장 작은 막대를 찾고 해당 막대를 기준으로 왼쪽과 오른쪽을 비교하는
	재귀적 방식으로 값을 구해나갔다.
	또한, 범위 내의 가장 작은 막대의 index를 세그먼트 트리를 이용하여 구하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_HEIGHT 1000000001
#define SEGTREE_MAX_SIZE 262144
typedef long long ll;

int n, S;
int histogram[SEGTREE_MAX_SIZE];
int segTree[SEGTREE_MAX_SIZE];

int query(int ql, int qr, int l, int r, int cur) {
	if (ql > r || qr < l)
		return 0;
	else if (ql <= l && qr >= r)
		return segTree[cur];

	int mid = (l + r) / 2;
	int left = query(ql, qr, l, mid, cur * 2);
	int right = query(ql, qr, mid + 1, r, cur * 2 + 1);

	return (histogram[left] <= histogram[right]) ? left : right;
}

ll solve(int l, int r) {
	if (l > r)
		return 0;

	int idx = query(l, r, 1, S, 1);
	ll ret = histogram[idx] * ((ll)r - l + 1);
	ret = max(ret, solve(l, idx - 1));
	ret = max(ret, solve(idx + 1, r));
	return ret;
}

void init() {
	memset(segTree, 0, sizeof(segTree));

	cin >> n;
	S = 1;
	while (S < n) S <<= 1;

	for (int i = 0; i <= S; i++)
		histogram[i] = MAX_HEIGHT;
	for (int i = 1; i <= n; i++)
		cin >> histogram[i];

	for (int i = S; i < 2 * S; i++)
		segTree[i] = i - S + 1;
	for (int i = S - 1; i > 0; i--) {
		if (histogram[segTree[i * 2]] > histogram[segTree[i * 2 + 1]])
			segTree[i] = segTree[i * 2 + 1];
		else
			segTree[i] = segTree[i * 2];
	}
}

int main(void) {
	fastio;

	while (1) {
		init();
		if (n == 0) break;

		cout << solve(1, n) << '\n';
	}
}