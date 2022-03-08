/**********************************************************************
작성일 : 2022-3-08
문제 :
	전기줄이 연결된 관계가 주어졌을 때 꼬인 전기줄이 없어지기 위해 제거해야하는
	전기줄의 최소개수를 구하라
풀이 :
	LIS의 길이를 구하고 전기줄 개수에서 빼주는 방법으로 구했다. 
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100001
using namespace std;

int n;
int line[MAX_SIZE];
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
	for (int i = 1; i <= n; i++) {
		if (indexList.empty() || indexList.back() < line[i]) {
			indexList.push_back(line[i]);
		}
		else {
			int idx = get_idx(line[i]);
			indexList[idx] = line[i];
		}
	}
	return (int)indexList.size();
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> line[i];
	}
}

int main() {
	fastio;

	init();
	cout << n - LIS();
}