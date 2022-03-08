/**********************************************************************
작성일 : 2022-3-08
문제 :
	Longest Increasing Subsequence를 구하는 문제
	보통 LIS의 길이만을 구하지만, 이 문제는 sequence 전체를 구해야한다.
풀이 :
	기본적인 LIS 구현에 배열의 각 원소가 indexList에서 몇번 째 원소인지
	저장하는 Index 배열을 이용하여 sequence 전체를 구한다.
시간 제한 : 3초
메모리 제한 : 512MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_N 1000001
using namespace std;

int n;
int arr[MAX_N], Index[MAX_N];
vector<int> indexList;

int get_index(int target) {
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
			Index[i] = (int)indexList.size() - 1;
		}
		else {
			int idx = get_index(arr[i]);
			indexList[idx] = arr[i];
			Index[i] = idx;
		}
	}
	return (int)indexList.size();
}
void print_seq() {
	stack<int> st;
	int idx = (int)indexList.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (Index[i] == idx) {
			st.push(arr[i]);
			idx--;
		}
	}
	
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
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
	cout << LIS() << '\n';
	print_seq();
}