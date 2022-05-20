#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int inDegree[501];
int buildTime[501], completeTime[501];
vector<int> adjlist[501];

void solve() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			completeTime[i] = buildTime[i];
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			completeTime[next] = max(completeTime[next], completeTime[now] + buildTime[next]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> buildTime[i];
		while (1) {
			int u; cin >> u;
			
			if (u == -1) break;
			
			adjlist[u].push_back(i);
			inDegree[i]++;
		}
	}
}

int main(void) {
	fastio;
	init();
	solve();

	for (int i = 1; i <= n; i++) {
		cout << completeTime[i] << '\n';
	}
}