#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, r, c;
int ans;

void solve(int rr, int cc, int RR, int CC, int cnt) {
	if (r < rr || r > RR || c < cc || c > CC)
		return;
	else if (rr == r && RR == r && cc == c && CC == c) {
		ans = cnt;
		return;
	}
	int hf = (RR - rr + 1) / 2;
	if (r >= rr + hf) {
		if (c >= cc + hf)
			solve(rr + hf, cc + hf, RR, CC, cnt + 3 * hf * hf);
		else
			solve(rr + hf, cc, RR, CC - hf, cnt + 2 * hf * hf);
	}
	else {
		if (c >= cc + hf)
			solve(rr, cc + hf, RR - hf, CC, cnt + hf * hf);
		else
			solve(rr, cc, RR - hf, CC - hf, cnt);
	}
}

void init() {
	cin >> n >> r >> c;
}

int main(void) {
	fastio;
	init();

	solve(0, 0, (1 << n) - 1, (1 << n) - 1, 0);
	cout << ans;
}