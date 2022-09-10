#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int sgn[40001];
vector<int> indexList;

int get_idx(int num) {
	int l = 0, r = (int)indexList.size();

	while (l < r) {
		int mid = (l + r) / 2;

		if (indexList[mid] >= num)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int LIS() {
	for (int i = 1; i <= n; i++) {
		int idx = get_idx(sgn[i]);

		if (idx < (int)indexList.size())
			indexList[idx] = sgn[i];
		else
			indexList.push_back(sgn[i]);
	}
	return (int)indexList.size();
}

void init() {
	indexList.clear();
	memset(sgn, 0, sizeof(sgn));

	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> sgn[i];
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();
		cout << LIS() << '\n';
	}
}