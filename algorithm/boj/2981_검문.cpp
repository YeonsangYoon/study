/**********************************************************************
작성일 : 2022-03-18
문제 :
	N개의 숫자를 m으로 나누었을 때 모두 같은 나머지를 가지는 m을 찾아
	오름차순으로 출력하라.
풀이 :
	각 숫자들의 차이를 diff배열에 저장하고 해당 차이의 gcd를 구한다.
	gcd값의 약수가 정답임.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn + m^0.5) (n : 숫자 개수, m : 숫자 범위)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int nums[100];
vector<int> diff;

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> nums[i];
	}
	sort(nums, nums + n);
	for (int i = 1; i < n; i++) {
		diff.push_back(nums[i] - nums[i - 1]);
	}
}

void solve() {
	int m = diff[0];
	for (int i = 1; i < (int)diff.size(); i++) {
		m = gcd(m, diff[i]);
	}
	
	vector<int> result;
	result.push_back(m);
	for (int i = 2; i * i <= m; i++) {
		if (m % i == 0) {
			result.push_back(i);
			if (i != m / i) result.push_back(m / i);
		}
	}
	sort(result.begin(), result.end());

	for (int& ans : result)
		cout << ans << ' ';
}

int main() {
	fastio;

	init();
	solve();
}