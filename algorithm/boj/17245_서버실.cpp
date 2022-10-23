#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define int int64_t

int n, totalCnt, maxFloor;
vector<int> server;

int solve() {
	int l = 0, r = maxFloor;

	while (l < r) {
		int mid = (l + r) / 2;
		int cnt = 0;
		for (int& com : server)
			cnt += (com > mid) ? mid : com;

		if (2 * cnt >= totalCnt)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

void init() {
	cin >> n;
	server = vector<int>(n * n);

	for (int i = 0; i < n * n; i++) {
		cin >> server[i];
		totalCnt += server[i];
		maxFloor = max(maxFloor, server[i]);
	}
}

int32_t main(void) {
	fastio;
	init();

	cout << solve();
}