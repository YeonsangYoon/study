#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int inDegree[1001];
vector<int> ans;
vector<int> adjlist[1001];

int DAG() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		ans.push_back(now);

		for (int& nex : adjlist[now]) {
			if (--inDegree[nex] == 0)
				q.push(nex);
		}
	}

	for (int i = 1; i <= n; i++)
		if (inDegree[i] > 0)
			return -1;
	return 1;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int cnt; cin >> cnt;
		int prev = 0;
		for (int j = 0; j < cnt; j++) {
			int cur; cin >> cur;
			if (prev != 0) {
				adjlist[prev].push_back(cur);
				inDegree[cur]++;
			}
			prev = cur;
		}
	}
}

int main(void) {
	fastio;
	init();

	if (-1 == DAG()) {
		cout << 0;
	}
	else {
		for (int& i : ans)
			cout << i << '\n';
	}
}