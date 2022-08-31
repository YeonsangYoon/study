#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define INF 1000000000

int f, s, g, u, d;
int dp[1000001];

int solve() {
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		if (now + u <= f && now + u >= 1) {
			if (dp[now + u] > dp[now] + 1) {
				dp[now + u] = dp[now] + 1;
				q.push(now + u);
			}
		}
		if (now - d <= f && now - d >= 1) {
			if (dp[now - d] > dp[now] + 1) {
				dp[now - d] = dp[now] + 1;
				q.push(now - d);
			}
		}
	}
	return (dp[g] == INF) ? -1 : dp[g];
}

void init() {
	cin >> f >> s >> g >> u >> d;
	for (int i = 0; i <= 1000000; i++)
		dp[i] = INF;
	dp[s] = 0;
}

int main(void) {
	fastio;
	init();

	int result = solve();
	if (result == -1)
		cout << "use the stairs";
	else
		cout << result;
}