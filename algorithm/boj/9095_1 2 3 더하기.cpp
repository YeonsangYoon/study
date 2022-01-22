/**********************************************************************
작성일 : 2022-1-22
문제 :
	정수 n이 주어졌을 때 1, 2, 3만을 더해서 만드는 경우의 수
풀이 :
	- 중복 조합 문제
	- dfs를 활용
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(?)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int cnt = 0;

void dfs(int n) {
	if (n == 0) cnt++;

	for (int i = 1; i <= 3; i++) {
		if (n < i) continue;
		dfs(n - i);
	}
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		cnt = 0;
		int n; cin >> n;
		dfs(n);
		cout << cnt << '\n';
	}
}