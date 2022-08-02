#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
bool isPrime[1001];

int solve() {
	for (int i = 2; i <= n; i++) {
		if (--k == 0) return i;

		if (isPrime[i]) {
			for (int j = 2 * i; j <= n; j += i) {
				if (--k == 0) return j;
				isPrime[j] = false;
			}
		}
	}
	return -1;
}

void init() {
	cin >> n >> k;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}