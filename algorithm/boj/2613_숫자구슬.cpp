/**********************************************************************
작성일 : 2022-3-10
문제 :
	n개의 숫자구슬을 m개의 그룹으로 나눴을 때 그룹 합의 최대값이 최소값이 되도록
	구분하고 해당 최댓값과 그룹의 인원을 순서대로 출력하라
풀이 :
	이분탐색을 통해 가능한 최댓값의 최소값을 찾았고, 가능한 그룹의 현황을 구하는
	코드를 구현하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int arr[301];

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

bool isPossible(int val) {
	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > val) {
			cnt++;
			sum = arr[i];
		}
	}
	return cnt + 1 <= m;
}

void solve() {
	int l = 0;
	for (int i = 0; i < n; i++)
		l = max(l, arr[i]);
	int r = 30000;

	while (l < r) {
		int mid = (l + r) / 2;

		if (isPossible(mid)) {
			r = mid;
		}
		else {
			l = mid + 1;
		}
	}

	cout << l << '\n';

	int cnt = 0;
	int sum = 0;
	for (int i = 0; i < n; i++) {
		sum += arr[i];
		if (sum > l) {
			cout << cnt << ' ';
			sum = arr[i];
			cnt = 0;
			m--;
		}
		cnt++;
		if (n - i == m) break;
	}
	while (m) {
		cout << cnt << ' ';
		cnt = 1;
		m--;
	}
}

int main() {
	fastio;

	init();
	solve();
}