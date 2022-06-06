/**********************************************************************
작성일 : 2022-6-06
문제 :
	n보다 큰 자연수 중 소수이면서 팰린드롬인 최소값을 구하라.
풀이 :
	에라토스테네스의 체를 통해 소수를 구하고, 단순 반복문을 통해 회문 검사를 했다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1003001
using namespace std;

int n;
bool isPrime[MAX + 1];

void set_prime_number() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= MAX; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= MAX; j += i) {
				isPrime[j] = false;
			}
		}
	}
}

bool isPalindrome(int num) {
	vector<int> v;
	while (num > 0) {
		v.push_back(num % 10);
		num /= 10;
	}

	int len = (int)v.size();
	for (int i = 0; i < len / 2 + 1; i++) {
		if (v[i] != v[len - i - 1])
			return false;
	}
	return true;
}

int solve() {
	for (int i = n; i <= MAX; i++) {
		if (isPrime[i] && isPalindrome(i))
			return i;
	}
}

int main(void) {
	fastio;

	cin >> n;
	set_prime_number();
	cout << solve();
}