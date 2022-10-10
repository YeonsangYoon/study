#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, h, t;
bool ans;
priority_queue<int> pq;

int solve() {
	for (int i = 1; i <= t; i++) {
		int now = pq.top(); pq.pop();
		if (now < h) {
			ans = true;
			return i - 1;
		}
		else if (now > 1)
			now /= 2;
		pq.push(now);
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

void init() {
	cin >> n >> h >> t;
	for (int i = 0; i < n; i++) {
		int tmp; cin >> tmp;
		pq.push(tmp);
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