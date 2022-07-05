#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 250000

struct checkPoint {
	int idx, x, y;
};
struct Query {
	int idx, a, b, hp;
	bool operator<(const Query& a) const {
		return hp < a.hp;
	}
};
struct edge {
	int a, b, dist;
	bool operator<(const edge& a) const {
		return dist > a.dist;
	}
};
struct disJointSet {
	int parent[MAX + 1];
	void init(int n) {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (parent[a] == a) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
bool xsort(checkPoint& a, checkPoint& b) {
	return a.x < b.x;
}
bool ysort(checkPoint& a, checkPoint& b) {
	return a.y < b.y;
}

int n, q;
vector<Query> query;
vector<checkPoint> xcp;
vector<checkPoint> ycp;
vector<pair<int, bool>> ans;
priority_queue<edge> pq;
disJointSet djs;

void init() {
	cin >> n >> q;
	djs.init(n);

	for (int i = 1; i <= n; i++) {
		int x, y;
		cin >> x >> y;
		xcp.push_back({ i, x, y });
		ycp.push_back({ i, x, y });
	}
	sort(xcp.begin(), xcp.end(), xsort);
	sort(ycp.begin(), ycp.end(), ysort);

	for (int i = 0; i < n - 1; i++) {
		pq.push({ xcp[i].idx, xcp[i + 1].idx, min(abs(xcp[i].x - xcp[i + 1].x), abs(xcp[i].y - xcp[i + 1].y)) });
		pq.push({ ycp[i].idx, ycp[i + 1].idx, min(abs(ycp[i].x - ycp[i + 1].x), abs(ycp[i].y - ycp[i + 1].y)) });
	}

	for (int i = 1; i <= q; i++) {
		int a, b, hp;
		cin >> a >> b >> hp;
		query.push_back({ i, a, b, hp });
	}
	sort(query.begin(), query.end());
}

int main(void) {
	fastio;
	init();

	for (Query &Q : query) {
		while (!pq.empty()) {
			if (pq.top().dist > Q.hp) break;

			edge now = pq.top(); pq.pop();
			djs.merge(now.a, now.b);
		}
		ans.push_back({ Q.idx, djs.find(Q.a) == djs.find(Q.b) });
	}

	sort(ans.begin(), ans.end());
	for (auto& a : ans) {
		if (a.second)
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}