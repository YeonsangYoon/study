/**********************************************************************
작성일 : 2022-1-18
문제 :
	주어진 수가 4개의 소수들의 합으로 만들 수 있는 지 확인하고 소수들을 출력하는 문제
풀이 :
	'골드바흐의 추측'을 사용하여 쉽게 구하였다.
		- 짝수 : 2 2 소수 소수
		- 홀수 : 2 3 소수 소수
	두 개의 소수는 for문을 통해 하나씩 비교하면서 수행했다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int isPrime[1000001];
void input() {
	cin >> n;
}
void eratos() {
	for (int i = 2; i <= n; i++)
		isPrime[i] = true;

	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
}
void solve() {
	if (n < 8) {		// 8미만은 불가능
		cout << -1;
	}
	else if (n % 2) {	// 홀수
		n -= 5;
		for (int i = 2; i <= n; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				cout << "2 3 " << i << " " << n - i;
				break;
			}
		}
	}
	else {				// 짝수
		n -= 4;
		for (int i = 2; i <= n; i++) {
			if (isPrime[i] && isPrime[n - i]) {
				cout << "2 2 " << i << " " << n - i;
				break;
			}
		}
	}
}

int main() {
	fastio;
	input();
	eratos();
	solve();
	return 0;
}