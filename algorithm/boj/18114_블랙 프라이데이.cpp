/**********************************************************************
작성일 : 2022-7-15
문제 :
	N개의 물건 중 3개 이하의 물건을 선택하여 무게 c를 만들고자 한다.
	만약 만들 수 있으면 1을 출력하고, 어떠한 경우에도 만들지 못하면 0을 출력하라.
풀이 :
	물건의 최대 개수는 5000개이므로 O(N^3)으로 나이브하게 구현하면 시간초과가 발생한다.
	따라서 2개를 선택하고 나머지 물건의 무게를 찾는 것은 이분탐색을 구현하여 구했다.
시간 제한 : 1초
메모리 제한 : 1024MB
예상 시간복잡도 : O(n^2logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, c;
vector<int> weight;

bool binary_search(int num, int s1, int s2) {
	int l = 0;
	int r = n - 1;

	while (l <= r) {
		int mid = (l + r) / 2;

		if (weight[mid] == num) {
			if (mid != s1 && mid != s2)
				return true;
			else
				return false;
		}
		else if (weight[mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return false;
}

int solve() {
	for (int i = 0; i < n; i++)
		if (weight[i] == c)
			return 1;

	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			int sum = weight[i] + weight[j];
			if (sum == c || binary_search(c - sum, i, j))
				return 1;
		}
	}
	return 0;
}

void init() {
	cin >> n >> c;
	for (int i = 0; i < n; i++) {
		int w; cin >> w;
		weight.push_back(w);
	}
	sort(weight.begin(), weight.end());
}

int main(void) {
	fastio;
	init();

	cout << solve();
}