#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
using namespace std;

int n;
int pre[1001], in[1001];

void solve(int pl, int pr, int il, int ir) {
	if (pl > pr || il > ir) return;

	int root = pre[pl];
	int idx;
	for (idx = il; idx <= ir; idx++) if (in[idx] == root) break;
	
	int leftlen = idx - il;
	int rightlen = ir - idx;

	solve(pl + 1, pl + leftlen, il, idx - 1);
	solve(pr - rightlen + 1, pr, idx + 1, ir);
	cout << root << ' ';
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> pre[i];
	for (int i = 1; i <= n; i++)
		cin >> in[i];
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		solve(1, n, 1, n);
		cout << '\n';
	}
}