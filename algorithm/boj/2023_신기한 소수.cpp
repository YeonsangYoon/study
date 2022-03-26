/**********************************************************************
작성일 : 2022-03-26
문제 :
	1 ~ 8인 n이 주어질 때 n자리의 자연수 중 신기한 소수를 오른차순으로 출력하라.
	신기한 소수의 예시 - 7331 (7331, 733, 73, 7 모두 소수인 경우)
풀이 :
	메모리 제한이 4mb이기 때문에 에라토스테네스는 메모리 초과가 발생한다.
	따라서 반복문을 소수 검사를 하는 방법을 선택하였다.
	
	또한 n자리 수 전부를 신기한 소수인지 검사하기 위해선 시간초과가 발생한다.
	따라서 dfs를 이용하여 수를 하나씩 추가하면서 소수인지 검사하도록 개선하였다.
시간 제한 : 2초
메모리 제한 : 4MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;

bool isPrime(int num) {
	if (num < 2) return false;

	for (int i = 2; i * i <= num; i++) {
		if (num % i == 0) return false;
	}
	return true;
}

void dfs(int cnt, int num) {
	if (cnt == n) {
		if (isPrime(num))
			cout << num << '\n';
	}

	for (int i = 0; i < 10; i++) {
		num = num * 10 + i;
		if (isPrime(num))
			dfs(cnt + 1, num);
		num /= 10;
	}
}

int main() {
	fastio;

	cin >> n;
	dfs(0, 0);
}