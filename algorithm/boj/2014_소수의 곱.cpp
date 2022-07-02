/**********************************************************************
작성일 : 2022-7-02
문제 :
	k개의 소수가 있다. 이 소수들 중에서 몇개를 곱해서 얻게되는 수들이 있을때,
	n번째의 수를 구하라.
풀이 :
	우선순위 큐를 활용하여 매 수를 뽑을 때 가장 작은 수를 선택하고
	해당 수에 k개의 수를 곱해서 다시 큐에 push한다.
	이때, 중복을 제거하기 위한 조건문을 추가하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

int n, k;
vector<ll> primes;
priority_queue<ll, vector<ll>, greater<ll>> pq;

int solve() {
	for (int i = 0; i < n - 1;i++) {
		ll now = pq.top(); pq.pop();

		for (ll& p : primes) {
			pq.push(now * p);
			if (now % p == 0)
				break;
		}
	}
	return pq.top();
}

void init() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int prime; cin >> prime;
		primes.push_back(prime);
		pq.push(prime);
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}