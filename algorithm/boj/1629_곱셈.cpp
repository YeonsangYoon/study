#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

ll a, b, c;

ll solve() {
	ll ret = 1;
	ll cur = a;

	for (int i = 0; i < 32; i++) {
		if (((ll)1 << i) & b) {
			ret *= cur;
			ret %= c;
		}
		cur = (cur * cur) % c;
	}

	return ret;
}

int main(void) {
	fastio;
	cin >> a >> b >> c;

	cout << solve();
}