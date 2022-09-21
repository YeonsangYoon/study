#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int mapping[100001], arr[100001];
vector<int> idx_list;

int get_idx(int num) {
	int l = 0, r = (int)idx_list.size();

	while (l < r) {
		int mid = (l + r) / 2;

		if (idx_list[mid] >= num)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int LIS() {
	for (int i = 1; i <= n; i++) {
		int idx = get_idx(arr[i]);

		if ((int)idx_list.size() > idx)
			idx_list[idx] = arr[i];
		else
			idx_list.push_back(arr[i]);
	}
	return (int)idx_list.size();
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int idx; cin >> idx;
		mapping[idx] = i;
	}
	for (int i = 1; i <= n; i++) {
		int idx; cin >> idx;
		arr[i] = mapping[idx];
	}
}

int main(void){
	fastio;
	init();

	cout << LIS();
}