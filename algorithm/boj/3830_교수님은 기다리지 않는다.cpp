#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int n, m;
struct disJointSet {
	int parent[100001];
	int diff[100001];
	void init() {
		for (int i = 1; i <= n; i++) {
			parent[i] = i;
			diff[i] = 0;
		}
	}
	int find(int n) {
		if (parent[n] == n) return n;

		int pa = find(parent[n]);
		diff[n] += diff[parent[n]];

		return parent[n] = pa;
	}
	void merge(int n1, int n2, ll weight) {
		int p1 = find(n1);
		int p2 = find(n2);

		if (p1 == p2) return;

		parent[p1] = p2;
		diff[p1] = diff[n2] - diff[n1] + weight;
	}

};
disJointSet djs;

void init() {
	cin >> n >> m;
	djs.init();
}

int main(void) {
	fastio;

	while (1) {
		init();
		
		if (n == 0 && m == 0) 
			break;

		for (int i = 0; i < m; i++) {
			char c; cin >> c;

			if (c == '!') {
				int a, b; ll w;
				cin >> a >> b >> w;
				djs.merge(a, b, w);
			}
			else {
				int a, b;
				cin >> a >> b;

				if (djs.find(a) == djs.find(b))
					cout << djs.diff[a] - djs.diff[b] << '\n';
				else
					cout << "UNKNOWN\n";
			}
		}
	}
}