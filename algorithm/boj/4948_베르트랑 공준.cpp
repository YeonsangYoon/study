#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_N 123456

int n;
bool isPrime[MAX_N * 2 + 1];

void init() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= MAX_N * 2; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= MAX_N * 2; j += i)
				isPrime[j] = false;
		}
	}
}

int main(void) {
	fastio;
	init();

	while (1) {
		cin >> n;
		if (n == 0) break;

		int cnt = 0;
		for (int i = n + 1; i <= 2 * n; i++) {
			if (isPrime[i])
				cnt++;
		}
		cout << cnt << '\n';
	}
}