#include <bits/stdc++.h>
using namespace std;

struct node {
	int u, w;
	bool operator<(const node& a) const {
		return a.w < w;
	}
};

int n;
int kind[50001];	// 0 : 쉼터, 1 : 출입구, 2 : 산봉우리
vector<int> dp;
vector<vector<node>> adjlist;

vector<int> solution(int n, vector<vector<int>> paths, vector<int> gates, vector<int> summits) {
	/* init */
	sort(summits.begin(), summits.end());
	adjlist = vector<vector<node>>(n + 1, vector<node>());
	dp = vector<int>(n + 1, 1000000000);
	for (int& g : gates) kind[g] = 1;
	for (int& s : summits) kind[s] = 2;
	for (auto& p : paths) {
		if (kind[p[0]] != 2 && kind[p[1]] != 1)
			adjlist[p[0]].push_back({ p[1], p[2] });
		if (kind[p[0]] != 1 && kind[p[1]] != 2)
			adjlist[p[1]].push_back({ p[0], p[2] });
	}
	/********/

	priority_queue<node> pq;
	for (int& g : gates) {
		pq.push({ g, 0 });
		dp[g] = 0;
	}

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dp[now.u] < now.w) continue;
		for (node& nex : adjlist[now.u]) {
			if (dp[nex.u] > max(now.w, nex.w)) {
				dp[nex.u] = max(now.w, nex.w);
				pq.push({ nex.u, dp[nex.u] });
			}
		}
	}
	int i = 0, its = 1000000000;
	for (int& s : summits) {
		if (dp[s] < its) {
			i = s;
			its = dp[s];
		}
	}
	return { i , its };
}