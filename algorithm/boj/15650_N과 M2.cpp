#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
vector<int> cur;

void dfs(int s, int cnt) {
	if (cnt == m) {
		for (int& i : cur)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = s; i <= n; i++) {
		cur.push_back(i);
		dfs(i + 1, cnt + 1);
		cur.pop_back();
	}
}

int main(void) {
	fastio;
	cin >> n >> m;

	dfs(1, 0);
}