#include <bits/stdc++.h>
using namespace std;

struct edge {
	int u, w;
};

int n;
int kind[50001];	// 0 : 쉼터, 1 : 출입구, 2 : 산봉우리
bool visited[50001];
vector<int> ans = { 50001, 100000000 };
vector<vector<edge>> adjlist;

bool cmp(vector<int>& a, vector<int>& b) {
	return a[2] < b[2];
}

void dfs(int cur, int its, int start) {
	if (its >= ans[1] || kind[cur] == 2) {
		return;
	}
	else if (kind[cur] == 1) {
		if (its < ans[1])
			ans = { start, its };
		return;
	}

	for (edge& e : adjlist[cur]) {
		if (!visited[e.u]) {
			visited[e.u] = true;
			dfs(e.u, max(its, e.w), start);
			visited[e.u] = false;
		}
	}
}

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	// init
	sort(summits.begin(), summits.end());
	sort(paths.begin(), paths.end(), cmp);
	adjlist = vector<vector<edge>>(n + 1, vector<edge>());
	for (auto& p : paths) {
		adjlist[p[0]].push_back({ p[1], p[2] });
		adjlist[p[1]].push_back({ p[0], p[2] });
	}
	for (int& g : gates) kind[g] = 1;
	for (int& s : summits) kind[s] = 2;

	for (int& s : summits) {
		if (ans[1] == paths[0][2]) break;
		visited[s] = true;
		kind[s] = -1;
		dfs(s, 0, s);
		kind[s] = 2;
		visited[s] = false;
	}
	return ans;
}