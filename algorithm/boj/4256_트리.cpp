#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
using namespace std;

int n;
int pre[1001], in[1001];

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

	}
}