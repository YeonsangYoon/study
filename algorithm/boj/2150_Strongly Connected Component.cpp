#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int id[10001];
bool visited[10001];
stack<int> st;
vector<int> adjlist[10001], radjlist[10001];
vector<vector<int>> scc;

void dfs(int cur) {
	visited[cur] = true;

	for (int& nex : adjlist[cur]) {
		if (!visited[nex])
			dfs(nex);
	}
	st.push(cur);
}

void add_node(int cur, int sccid) {
	visited[cur] = true;
	id[cur] = sccid;

	for (int& nex : radjlist[cur]) {
		if (!visited[nex])
			add_node(nex, sccid);
	}
}

void print_scc() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}
	memset(visited, false, sizeof(visited));

	int sccid = 1;
	while (!st.empty()) {
		int now = st.top(); st.pop();
		if (!visited[now]) {
			add_node(now, sccid);
			sccid++;
		}
	}
	memset(visited, false, sizeof(visited));
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			int sccid = id[i];
			visited[i] = true;
			cout << i << ' ';
			for (int j = i + 1; j <= n; j++) {
				if (id[j] == sccid) {
					cout << j << ' ';
					visited[j] = true;
				}
			}
			cout << -1 << '\n';
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		radjlist[b].push_back(a);
	}
}

int main(void) {
	fastio;
	init();

	print_scc();
}