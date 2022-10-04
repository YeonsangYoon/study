#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define N_SIZE 10000

int n, m;
int sccID[N_SIZE + 1];
bool visited[N_SIZE + 1];
stack<int> st;
vector<int> adjlist[N_SIZE + 1], radjlist[N_SIZE + 1];
vector<vector<int>> sccList;

void dfs1(int cur) {
	visited[cur] = true;

	for (int& nex : adjlist[cur]) {
		if (!visited[nex])
			dfs1(nex);
	}
	st.push(cur);
}
void dfs2(int cur, int id, vector<int> &v) {
	visited[cur] = true;
	sccID[cur] = id;
	v.push_back(cur);

	for (int& nex : radjlist[cur]) {
		if (!visited[nex])
			dfs2(nex, id, v);
	}
}

int get_scc() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs1(i);
	}
	memset(visited, false, sizeof(visited));

	int id = 0;
	while (!st.empty()) {
		int now = st.top(); st.pop();

		if (!visited[now]) {
			vector<int> tmp;
			dfs2(now, id, tmp);
			sort(tmp.begin(), tmp.end());
			sccList.push_back(tmp);
			id++;
		}
	}
	return id;
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
	
	int cnt = get_scc();
	memset(visited, false, sizeof(visited));
	cout << cnt << '\n';
	for (int i = 1; i <= n; i++) {
		if (!visited[i]) {
			for (int& j : sccList[sccID[i]]) {
				cout << j << ' ';
				visited[j] = true;
			}
			cout << -1 << '\n';
		}
	}
}