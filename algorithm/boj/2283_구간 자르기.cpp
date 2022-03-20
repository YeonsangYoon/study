#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
int maxPoint = 0;
struct node {
	int s, e;
};
vector<node> lines;

int get_sum(int l, int r) {
	int sum = 0;
	for (node& line : lines) {
		if (line.s >= r || line.e <= l)
			continue;
		sum += (min(r, line.e) - max(l, line.s));
	}
	return sum;
}

node solve() {
	int l = 0;
	int r = 1;

	while (l <= r && l <= maxPoint && r <= maxPoint) {
		int sum = get_sum(l, r);

		if (sum > k) {
			l++;
		}
		else if (sum < k) {
			r++;
		}
		else {
			return { l, r };
		}
	}
	return { 0, 0 };
}

void init() {
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		lines.push_back({ s, e });
		maxPoint = max(maxPoint, e);
	}
}
int main() {
	fastio;

	init();
	node result = solve();

	cout << result.s << ' ' << result.e;
}