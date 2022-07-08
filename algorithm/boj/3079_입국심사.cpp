/**********************************************************************
작성일 : 2022-07-08
작성자 : 윤연상
문제 :
	n개의 입국심사대에 m명의 사람이 입국심사를 받는다.
	각 입국심사대에서 걸리는 시간이 주어질 때, m명의 사람이 모두 입국심사를 완료하는
	최소 시간을 구하라.
풀이 :
	이분탐색을 활용하여 최소값을 구하였다.
	걸리는 시간에 각 심사대에서 걸리는 시간을 나눠 더해주면 해당 시간내에 
	처리할 수 있는 사람의 최대값을 구할 수 있다. 
	이 값을 기준으로 이분탐색을 진행하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 100000
typedef long long ll;

int n, m;
ll maxTime;
ll times[MAX + 1];

ll solve() {
	ll l = 0, r = maxTime * m;

	while (l < r) {
		ll mid = (l + r) / 2;
		ll cnt = 0;
		for (int i = 0; i < n; i++)
			cnt += (mid / times[i]);
		
		if (cnt >= m) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	return l;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> times[i];
		maxTime = max(maxTime, times[i]);
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}