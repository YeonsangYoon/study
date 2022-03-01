#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
using namespace std;

class disJointSet {
private:
	int parent[MAX];
public:
	int g, p;
	void init(int g, int p) {
		this->g = g;
		this->p = p;
		for (int i = 0; i <= g; i++) {
			this->parent[i] = i;
		}
	}
	int find(int a) {
		if (a == this->parent[a])
			return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a > b) swap(a, b);
		parent[b] = a;
	}
};
disJointSet djs;

int solve() {
	int ret = 0;
	for (int i = 0; i < djs.p; i++) {
		int range; cin >> range;
		int gate = djs.find(range);
		if (gate > 0) {
			djs.merge(range, gate - 1);
			ret++;
		}
		else {
			break;
		}
	}
	return ret;
}
void init() {
	int g, p;
	cin >> g >> p;
	djs.init(g, p);
}

int main() {
	fastio;

	init();
	cout << solve();
}