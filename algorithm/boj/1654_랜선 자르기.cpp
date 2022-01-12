/**********************************************************************
작성일 : 2022-01-12
문제 :
	K개의 랜선을 동일한 길이의 N개의 랜선으로 자를 때 가능한 최대의 길이는?
	1≦ K ≦ 10000, 1 ≦ N ≦ 1000000
풀이 :
	난이도가 실버3인데 골드 같음
	문제를 접근했을 때 전에 풀었던 내용하고 비슷해서 바로 이분탐색인 것을 눈치챘음

	일단 이분탐색을 위한 범위를 설정해야함
	최소값은 1로 하고, 최댓값은 다음과 같이 설정했다.
	만약 K개의 랜선이 모두 같은 크기로 나눴을 때 남은 랜선이 0cm일 때 최대값을 가진다.
	다시말해 K개의 랜선을 다 이어붙이고 이를 N으로 나눈 값이 최대값이다.

	이분탐색을 구현할 때 조심해야하는 것은 정확한 값을 찾는 것이 아니라 해당 조건을 만족하는
	모든 길이 중 '최대값'을 찾는 것임. 이를 유의해야한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll k, n;
ll maxLen = 0;
vector<ll> lines;

void init() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		ll a; cin >> a;
		lines.push_back(a);
		maxLen += a;
	}

	maxLen /= n;	// 범위의 최대값 설정
}
ll get_count(ll len) {	
	// 해당 길이로 잘랐을 때 몇개를 만들지 계산
	ll cnt = 0;
	for (ll& i : lines) {
		cnt += (i / len);
	}
	return cnt;
}
ll solve() {
	// 이분탐색
	ll left = 1;
	ll right = maxLen;

	while (left <= right) {
		ll mid = (left + right) / 2;
		ll ret = get_count(mid);

		if (ret < n) {
			if (left == right)
				right = mid - 1;
			else
				right = mid;
		}
		else {
			left = mid + 1;
		}
	}

	return right;
}

int main() {
	fastio;

	init();
	cout << solve();
}