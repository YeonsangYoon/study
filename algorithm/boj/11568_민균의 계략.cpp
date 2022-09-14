#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int card[1001];
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
		int idx = get_idx(card[i]);

		if (idx < (int)indexList.size())
			indexList[idx] = card[i];
		else
			indexList.push_back(card[i]);
	}
	return (int)indexList.size();
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> card[i];
}

int main(void) {
	fastio;
	init();

	cout << LIS();
}