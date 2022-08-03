/**********************************************************************
작성일 : 2022-08-03
작성자 : 윤연상
문제 :
	에라토스테네스의 체를 수행할 때, k번 째 지우는 수를 구하라.
	1. 2부터 N까지 모든 정수를 적는다.
	2. 아직 지우지 않은 수 중 가장 작은 수를 찾는다. 이것을 P라고 하고, 이 수는 소수이다.
	3. P를 지우고, 아직 지우지 않은 P의 배수를 크기 순서대로 지운다.
	4. 아직 모든 수를 지우지 않았다면, 다시 2번 단계로 간다.
풀이 :
	에라토스테네스의 체를 구현하여 k번 째 지우는 수를 구하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
bool isPrime[1001];

int solve() {
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			if (--k == 0) return i;

			for (int j = 2 * i; j <= n; j += i) {
				if (isPrime[j]) {
					if (--k == 0) return j;
				}
				isPrime[j] = false;
			}
		}
	}
	return -1;
}

void init() {
	cin >> n >> k;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
}

int main(void) {
	fastio;
	init();

	cout << solve();

	return 0;
}