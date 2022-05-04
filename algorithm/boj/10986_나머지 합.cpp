/**********************************************************************
작성일 : 2022-05-04
문제 :
	n개의 원소를 가진 수열 A가 있을 때,
	구간의 합이 M으로 나누어 떨어지는 구간의 개수를 구하라.
풀이 :
	누적합 배열을 구하고, 각 누적합의 값의 개수를 기록하는 cnt배열을 만든다.
	구간합이 m으로 나누어 떨어지는 것이라면 선택된 두 개의 누적합의 나머지가 같은 경우이다.
	따라서 간단한 수학 계산으로 개수를 구하였다.
	이때, 구하고자하는 개수의 최대값은 long long으로 표현해야한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int n, m;
ll sum[1000001];
ll cnt[1001];

ll solve() {
	for (int i = 1; i <= n; i++) {
		cnt[sum[i]]++;
	}

	ll ret = cnt[0];
	for (int i = 0; i < m; i++) {
		ret += (cnt[i] * (cnt[i] - 1) / 2);
	}
	return ret;
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		ll a; cin >> a;
		sum[i] = (sum[i - 1] + a) % m;
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}