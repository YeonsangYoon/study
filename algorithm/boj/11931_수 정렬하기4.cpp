#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<int> arr;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(-num);
	}
}

int main(void) {
	fastio;
	init();

	sort(arr.begin(), arr.end());

	for (int& i : arr)
		cout << -i << '\n';
}