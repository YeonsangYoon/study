/**********************************************************************
작성일 : 2022-01-16
문제 :
	총 N개의 집에 C개의 공유기를 설치하려고 할 때 가장 인접한 두 공유기 사이의 최대 거리를 구하라
	(한개의 집에는 한개의 공유기만 설치 가능)
풀이 :
	이분탐색을 떠올리는 과정이 까다로웠고, 구현은 그동안의 연습때문에 수월했다.
	
	어떤 특정 값을 찾거나, ~~를 만족하는 최대값, 최소값을 찾는 경우에 이분탐색을 사용하기 적합한 것 같다.
	이 과정에서 정렬이 되어있거나 정렬을 해도 시간초과가 나지 않아야 한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, c;
int x[200001];


void init() {
	// 입력 및 초기화
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		cin >> x[i];
	}
}
bool can_install_wifi(int cnt, int mindist) {
	// 공유기의 최소 거리가 mindist일 때 cnt개만큼 설치 가능 여부를 리턴
	int cur = x[0];
	cnt--;

	for (int i = 1; i < n; i++) {
		if (x[i] - cur >= mindist) {
			cur = x[i];
			if (--cnt == 0)
				break;
		}
	}
	return cnt == 0;
}
int solve() {			// 이분탐색
	sort(x, x + n);		// 좌표순으로 정렬

	int left = 1;
	int right = x[n - 1] - x[0];

	while (left < right) {
		int mid = (left + right) / 2;

		if (can_install_wifi(c, mid)) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}

	if (can_install_wifi(c, right)) {
		return right;
	}
	else {
		return right - 1;
	}
}

int main() {
	fastio;

	init();
	cout << solve();

	return 0;
}