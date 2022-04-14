/**********************************************************************
작성일 : 2022-04-14
문제 :
	함수 f는 {1, 2, ..., m} -> {1, 2, ..., m}을 만족한다. 
	이때 다음의 쿼리를 수행하는 프로그램을 작성하라.
	쿼리 : n, x가 주어지고, f를 n번 합성한 fn(x)의 값을 구하라.
풀이 :
	m의 최대값은 200000이고 수행할 쿼리의 최대 수는 500000만이다. 
	따라서 나이브하게 합성함수 쿼리를 O(n)으로 구현하면 시간초과가 발생한다.

	n을 2의 거듭제곱의 합(이진수)으로 나타내고 해당 합성합수들을 미리 구해놓으면
	각 쿼리를 O(logn)의 시간복잡도로 구현가능하다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(qlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_M 200001
#define Pmax 20
using namespace std;

int m, q;
int fn[Pmax + 1][MAX_M];

int get_fn(int n, int x) {
	for (int i = Pmax; i >= 0; i--) {
		if ((1 << i) <= n) {
			x = fn[i][x];
			n -= (1 << i);
		}
	}
	return x;
}

void init() {
	cin >> m;
	for (int x = 1; x <= m; x++) {
		cin >> fn[0][x];
	}

	for (int i = 1; (1 << i) <= 500000; i++) {
		for (int x = 1; x <= m; x++) {
			fn[i][x] = fn[i - 1][fn[i - 1][x]];
		}
	}
}

int main(void) {
	fastio;
	init();

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int n, x;
		cin >> n >> x;
		cout << get_fn(n, x) << '\n';
	}
}