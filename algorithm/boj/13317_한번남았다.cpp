#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(void) {
	fastio;

	int n = 50;
	int m = 50;

	cout << n << ' ' << m << '\n';
	cout << "1 50 -1\n";
	for (int i = 2; i < m; i++) {
		cout << i << ' ' << (i + n - 1) % n << ' ' << -1 << '\n';
	}
	cout << "50 49 1";
}