#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int line[501];
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
	for (int i = 1; i <= 500; i++) {
		if (line[i] != -1) {
			int idx = get_idx(line[i]);

			if ((int)indexList.size() > idx)
				indexList[idx] = line[i];
			else
				indexList.push_back(line[i]);
		}
	}
	return (int)indexList.size();
}

void init() {
	for (int i = 1; i <= 500; i++)
		line[i] = -1;
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line[a] = b;
	}
}

int main(void) {
	fastio;
	init();
	
	cout << n - LIS();
}