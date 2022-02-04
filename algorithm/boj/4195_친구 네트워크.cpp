#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct node {
	int idx;
	int setCnt;
};
node parent[200002];
vector<pair<int, int>> network;
map<string, int> id;

int find(int a) {
	if (parent[a].idx == a)
		return a;
	return find(parent[a].idx);
}
int merge(int a, int b) {
	a = find(a);
	b = find(b);
	if (a == b)
		return parent[a].setCnt;

	parent[a].idx = b;
	parent[b].setCnt += parent[a].setCnt;
	return parent[b].setCnt;
}
void init() {
	vector<pair<int, int>>().swap(network);
	map<string, int>().swap(id);

	int n, cnt = 1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		string a, b;
		cin >> a >> b;
		if (!id[a])
			id[a] = cnt++;
		if (!id[b])
			id[b] = cnt++;

		network.push_back(make_pair(id[a], id[b]));
	}
	for (int i = 0; i <= 200001; i++) {
		parent[i].idx = i;
		parent[i].setCnt = 1;
	}
}
int main() {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		
		for (auto& i : network) {
			cout << merge(i.first, i.second) << '\n';
		}
		continue;
	}
}