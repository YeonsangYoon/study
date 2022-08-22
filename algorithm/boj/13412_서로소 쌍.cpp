/**********************************************************************
작성일 : 2022-08-22
문제 :
	두 자연수 a, b가 있을 때 두 자연수는 서로소이면서 최소공배수가 n인 경우의 수를 구하라.
풀이 :
	gcd 함수를 구현하고 n의 약수를 구해 서로소인지 확인하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^(1/2))
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, cnt;

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void init() {
	cin >> n;
	cnt = 0;
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

		for (int j = 1; (j * j) <= n; j++) {
			if (n % j) continue;
			if (gcd(j, n / j) == 1) cnt++;
		}
		cout << cnt << '\n';
	}
}