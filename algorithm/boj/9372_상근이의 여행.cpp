#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct disJointSet {
	int parent[1001];
	void init(int a) {
		for (int i = 1; i <= a; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};

int n, m;
disJointSet djs;

void init() {
	cin >> n >> m;
	djs.init(n);
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

	}
}