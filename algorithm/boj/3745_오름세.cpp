#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int stock[100001];
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
	for (int i = 0; i < n; i++) {
		int idx = get_idx(stock[i]);

		if (idx < (int)indexList.size()) {
			indexList[idx] = stock[i];
		}
		else {
			indexList.push_back(stock[i]);
		}
	}
	return (int)indexList.size();
}

void init() {
	indexList.clear();
	for (int i = 0; i < n; i++)
		cin >> stock[i];
}

int main(void) {
	fastio;

	while (cin >> n) {
		init();
		cout << LIS() << '\n';
	}
}