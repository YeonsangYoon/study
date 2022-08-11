/**********************************************************************
작성일 : 2022-8-11
문제 :
	n개의 묘목을 심어서 모두 나무로 자라게 하기 위한 최소 일수를 구하라.
	각 묘목의 자라는 시간이 주어지고, 묘목은 하루에 하나씩만 심을 수 있다.
풀이 :
	단순히 오래걸리는 묘목먼저 심어야하는 그리디 문제이다.
	힙을 이용하여 오래걸리는 묘목 순서대로 심어서 걸리는 날짜를 확인하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
priority_queue<int> pq;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int tree; cin >> tree;
		pq.push(tree);
	}
}

int main(void) {
	fastio;
	init();

	int cur = 2;
	int ans = 0;
	while (!pq.empty()) {
		ans = max(ans, pq.top() + cur++);
		pq.pop();
	}
	cout << ans;
}