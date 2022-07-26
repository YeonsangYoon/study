#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_N 1000001
#define INF 100000000

int n;
int dp[MAX_N], parent[MAX_N];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		dp[i] = INF;
}

int main(void) {
	fastio;
	init();

	for (int i = n; i > 0; i--) {
		if (dp[i - 1] > dp[i] + 1) {
			dp[i - 1] = dp[i] + 1;
			parent[i - 1] = i;
		}
		if (i % 2 == 0 && dp[i / 2] > dp[i] + 1) {
			dp[i / 2] = dp[i] + 1;
			parent[i / 2] = i;
		}
		if (i % 3 == 0 && dp[i / 3] > dp[i] + 1) {
			dp[i / 3] = dp[i] + 1;
			parent[i / 3] = i;
		}
	}

	int cur = 1;
	stack<int> st;
	while (cur != n) {
		st.push(cur);
		cur = parent[cur];
	}

	cout << dp[1] << '\n' << n << ' ';
	while (!st.empty()) {
		cout << st.top() << ' ';
		st.pop();
	}
}