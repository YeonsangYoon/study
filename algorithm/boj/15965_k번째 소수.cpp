#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 7368788

int k;
bool isPrime[MAX];

int solve() {
	int cnt = 0;
	for (int i = 2; i < MAX; i++) {
		if (isPrime[i]) {
			if (++cnt == k) return i;
			for (int j = i * 2; j < MAX; j += i)
				isPrime[j] = false;
		}
	}
}

void init() {
	cin >> k;
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}