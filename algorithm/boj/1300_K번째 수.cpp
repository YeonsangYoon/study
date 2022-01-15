/**********************************************************************
작성일 : 2022-01-15
문제 :
	크기가 N이고 A[i][j] = i * j를 만족하는 이차원 배열을 B[k]인 일차원 배열로 정렬하여 압축시킬때
	k번째 수를 구하라
풀이 :
	처음 접했을 때 약수의 개수를 찾아가면서 k번째 수를 찾았다. => 시간초과

	감이 안잡혀 다른 사람의 풀이를 찾았고 이분탐색을 사용하였다.
	=> 구하고자 하는 수는 반드시 1~k의 사이(각 수는 반드시 1번 이상 사용하기 때문에)
	=> 만약 k번째 수가 x라하면 이차원 배열에서 x보다 작은 수의 개수를 찾고
	=> 만족 여부에 따라 범위를 축소해간다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k;

void init() {
	cin >> n >> k;
}
int get_count(int num) {
	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		cnt += min(n, num / i);
		if (i > num) break;
	}
	return cnt;
}
int solve() {
	int left = 1;
	int right = k;
	
	while (left < right) {
		int mid = (left + right) / 2;
		int count = get_count(mid);

		if (count < k) {
			left = mid + 1;
		}
		else {
			right = mid;
		}
	}
	
	if (get_count(right - 1) < k) {
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
}