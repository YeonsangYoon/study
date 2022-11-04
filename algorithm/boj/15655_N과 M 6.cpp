#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
vector<int> arr, selected;

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		arr.push_back(num);
	}
	sort(arr.begin(), arr.end());
}

void solve(int cnt, int idx) {
	if (cnt == m) {
		for (int& i : selected)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = idx; i < n; i++) {
		selected.push_back(arr[i]);
		solve(cnt + 1, i + 1);
		selected.pop_back();
	}
}

int main(void) {
	fastio;
	init();

	solve(0, 0);
}