/**********************************************************************
작성일 : 2022-3-09
문제 :
	Longest Increasing Subsequence를 구하는 문제
	길이만 구하는 문제이므로 indexList만 구현한다.
풀이 :
	LIS 구현
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;

int n;
int arr[MAX_SIZE];
vector<int> indexList;

int get_idx(int target) {
	int l = 0;
	int r = (int)indexList.size() - 1;

	while (l < r) {
		int mid = (l + r) / 2;

		if (indexList[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return (indexList[r] < target) ? r + 1 : r;
}

int LIS() {
	for (int i = 0; i < n; i++) {
		if (i == 0 || indexList.back() < arr[i]) {
			indexList.push_back(arr[i]);
		}
		else {
			int idx = get_idx(arr[i]);
			indexList[idx] = arr[i];
		}
	}
	return (int)indexList.size();
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
}

int main() {
	fastio;

	init();
	cout << LIS();
}