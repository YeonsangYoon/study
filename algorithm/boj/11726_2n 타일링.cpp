/**********************************************************************
작성일 : 2022-5-26
문제 :
	2 x n 크기의 직사각형을 1x2, 2x1 타일로 채우는 방법의 수를 구하라.
풀이 :
	완전탐색시 수행시간이 매우 길기 때문에 dp를 통해 시간복잡도를 최적화하였다.
	또한, dp 수행의 범위가 일정하기 때문에 슬라이딩 윈도우를 통해 메모리도 줄였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int a, b, c;

int solve() {
	if (n == 1)
		return 1;
	else if (n == 2)
		return 2;

	a = 1, b = 2;
	for (int i = 0; i < n - 2; i++) {
		c = (a + b) % 10007;
		a = b;
		b = c;
	}
	return c;
}

int main(void) {
	fastio;
	cin >> n;

	cout << solve();
}