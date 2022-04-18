/**********************************************************************
작성일 : 2022-04-18
문제 :
	무한수열 A는 다음의 규칙을 가진다.
		- A[0] = 1
		- A[i] = A[i/p] + A[i/q]
	n, p, q가 주어질 때 A[n]을 구하라.
풀이 :
	재귀를 활용하여 완전탐색을 수행하였다.
	중복호출을 방지하기 위해 map을 활용하여 이미 계산된 값은 memo를 하여 저장하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nCl)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

ll n, p, q;
map<ll, ll> dp;

ll dfs(ll cur) {
	if (cur == 0) return 1;
	
	ll a = (dp[cur / p]) ? dp[cur / p] : dfs(cur / p);
	ll b = (dp[cur / q]) ? dp[cur / q] : dfs(cur / q);
	
	return dp[cur] = a + b;
}

void init() {
	cin >> n >> p >> q;
}

int main(void) {
	fastio;
	init();

	cout << dfs(n);
}