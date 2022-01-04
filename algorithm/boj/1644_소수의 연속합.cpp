/**********************************************************************
작성일 : 2022-01-04
작성자 : 윤연상
문제 :
	1 ≤ N ≤ 4,000,000인 자연수 N에 대하여 연속된 소수들의 합으로 N을 만들 수 있는 경우의 수
풀이 :
	- 소수를 구해야 하기 때문에 에라토스테네스의 체를 활용하여 소수 배열을 구하였다.
	- 소수의 연속합을 다루기 위해 2가지 선택지 중 고민했다.

	1. sumPN[i] : 1번째 소수 ~ i번째 소수까지의 합
	2. sumPN[i][j] : i번째 소수 ~ j번째 소수까지의 합

	N의 최대값이 4000,000 이었고 디버깅을 통해 1~4000000사이 소수의 개수는 대략 28만개인것을 확인
	나이브하게 2차원배열을 순회하는 방법은 시간초과가 난다. 

	때문에 투포인터 기법을 활용하여 1차원 배열을 순회하는 방법으로 구현하였다. 
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

bool isPrime[4000001];
vector<int> PN;
vector<ll> sumPN;

void get_init_condi(int n) {
	// 에라토스테네스의 체
	for (int i = 2; i <= n; i++) {
		isPrime[i] = true;
	}
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				isPrime[j] = false;
			}
		}
	}
	// 소수 배열 초기화
	for (int i = 2; i <= n; i++) {
		if (isPrime[i]) {
			PN.push_back(i);
		}
	}
	// 연속합 배열 초기화
	ll sum = 0;
	sumPN.push_back(0);	// 0을 추가해야 자기 자신도 확인 가능
	for (int i = 0; i < (int)PN.size(); i++) {
		sum += PN[i];
		sumPN.push_back(sum);
	}
}

int solve(int n) {
	// 투 포인터
	int cnt = 0;
	int l = 0;
	int r = 0;
	int size = (int)sumPN.size();

	while (l < size && r < size) {
		ll sum = sumPN[r] - sumPN[l];

		if (sum == n) {
			cnt++;
			l++; r++;
		}
		else if (sum < n) {
			r++;
		}
		else {
			l++;
		}
	}
	return cnt;
}

int main() {
	fastio;

	int n; cin >> n;
	get_init_condi(n);
	cout << solve(n);

	return 0;
}