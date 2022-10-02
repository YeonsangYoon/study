#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int sccId[100001], inDegree[100001];
bool visited[100001];
stack<int> st;
vector<int> adjlist[100001], radjlist[100001];

void dfs(int cur) {
	visited[cur] = true;

	for (int& nex : adjlist[cur]) {
		if (!visited[nex])
			dfs(nex);
	}
	st.push(cur);
}

void set_id(int cur, int id) {
	visited[cur] = true;
	sccId[cur] = id;

	for (int& nex : radjlist[cur]) {
		if (!visited[nex])
			set_id(nex, id);
	}
}

int set_scc() {
	for (int i = 1; i <= n; i++) {
		if (!visited[i])
			dfs(i);
	}
	memset(visited, false, sizeof(visited));

	int id = 1;
	while (!st.empty()) {
		int now = st.top(); st.pop();
		if (sccId[now] == 0) {
			set_id(now, id);
			id++;
		}
	}

	for (int i = 1; i <= n; i++) {
		for (int& j : adjlist[i]) {
			if (sccId[i] != sccId[j])
				inDegree[sccId[j]]++;
		}
	}
	return id - 1;
}

void init() {
	memset(sccId, 0, sizeof(sccId));
	memset(inDegree, 0, sizeof(inDegree));
	memset(visited, false, sizeof(visited));

	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
		radjlist[i].clear();
	}
	for (int i = 0; i < m; i++) {
		int x, y;
		cin >> x >> y;
		adjlist[x].push_back(y);
		radjlist[y].push_back(x);
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		int sccCnt = set_scc();

		int cnt = 0;
		for (int i = 1; i <= sccCnt; i++)
			if (inDegree[i] == 0)
				cnt++;
		cout << cnt << '\n';
	}
}