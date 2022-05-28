#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int f, ptr;
map<string, int> id;

struct disJointSet {
	int parent[200001];
	int cnt[200001];
	void init() {
		for (int i = 1; i <= 2 * f + 1; i++) {
			parent[i] = i;
			cnt[i] = 1;
		}
	}
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
		cnt[b] += cnt[a];
	}
};
disJointSet djs;

int add_network(string A, string B) {
	if (!id[A]) id[A] = ptr++;
	if (!id[B]) id[B] = ptr++;

	int a = id[A];  int b = id[B];

	djs.merge(a, b);
	return djs.cnt[djs.find(a)];
}

void init() {
	cin >> f;
	ptr = 1;
	id = {};
	djs.init();
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

		for (int j = 0; j < f; j++) {
			string a, b;
			cin >> a >> b;

			cout << add_network(a, b) << '\n';
		}
	}
}