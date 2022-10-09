#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, h, t;
bool ans;
priority_queue<int> pq;

void init() {
	cin >> n >> h;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp);
	}
}

int solve() {
	for (int i = 1; i <= t; i++) {
		int now = pq.top(); pq.pop();

		if (now >= h) {
			pq.push(now / 2);
		}
		else {
			ans = true;
			return i - 1;
		}
	}
	if (pq.top() < h) {
		ans = true;
		return t;
	}
	else {
		ans = false;
		return pq.top();
	}
}

int main(void) {
	fastio;
	init();
	int result = solve();

	if (ans)
		cout << "YES\n";
	else
		cout << "NO\n";
	cout << result;
}