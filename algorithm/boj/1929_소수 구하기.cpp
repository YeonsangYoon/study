/**********************************************************************
작성일 : 2022-1-25
문제 :
	m과n 사이의 자연수 중 소수를 찾아 출력하라
풀이 :
	대량의 소수를 구하는 경우 '에라토스테네스의 체'가 효율적이다.
	그냥 단순히 에라토스테네스를 구현하는 간단한 문제
		- 하지만, 배열을 크게 선언해야해서 메모리 측면에서는 다소 비효율적
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(nloglogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
bool isPrime[1000001];

void init() {
	cin >> m >> n;
}
void solve() {
	for (int i = 2; i <= n; i++) {
		isPrime[i] = true;
	}

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i)
				isPrime[j] = false;
		}
	}

	for (int i = m; i <= n; i++)
		if (isPrime[i])
			cout << i << '\n';
}

int main() {
	fastio;

	init();
	solve();
}