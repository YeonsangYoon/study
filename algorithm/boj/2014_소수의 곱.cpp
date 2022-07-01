/*
*  k^0 + k^1 + k^2 + k^3
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

int n, k, len, maxVal;
vector<ll> primes;
map<ll, bool> isIn;

int solve() {
	priority_queue<ll, vector<ll>, greater<ll>> pq;
	for (ll& p : primes) {
		pq.push(p);
		isIn[p] = true;
	}

	int cnt = 0;
	ll now = 0;
	while (cnt < n) {
			now = pq.top(); pq.pop();

		for (ll& p : primes) {
			ll next = p * now;
			if (!isIn[next] && (int)pq.size() < n) {
				pq.push(next);
				isIn[next] = true;
			}
		}
		cnt++;
	}
	return now;
}

void init() {
	cin >> k >> n;
	for (int i = 0; i < k; i++) {
		int prime; cin >> prime;
		primes.push_back(prime);
	}
}

int main(void) {
	fastio;
	init();

	cout << solve();
}