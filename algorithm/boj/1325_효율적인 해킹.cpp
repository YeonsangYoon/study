#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
bool visited[10001];
vector<int> adjlist[10001];

int bfs(int root) {
	memset(visited, false, sizeof(visited));
	visited[root] = true;

	int cnt = 1;
	queue<int> q;
	q.push(root);

	while (!q.empty()) {
		int now = q.front(); q.pop();
		cnt++;

		for (int& nex : adjlist[now]) {
			if (!visited[nex]) {
				visited[nex] = true;
				q.push(nex);
			}
		}
	}
	return cnt;
}

vector<int> solve() {
	vector<int> ret;

	int maxVal = 0;
	for (int i = 1; i <= n; i++) {
		int result = bfs(i);

		if (result > maxVal) {
			maxVal = result;
			ret.clear();
			ret.push_back(i);
		}
		else if (result == maxVal) {
			ret.push_back(i);
		}
	}
	return ret;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[b].push_back(a);
	}
}

int main(void) {
	fastio;
	init();

	vector<int> ans = solve();
	for (int& i : ans)
		cout << i << ' ';
}