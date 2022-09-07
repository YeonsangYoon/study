#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
int stock[10001];
vector<int> index_list;

int get_index(int num) {
	int l = 0, r = (int)index_list.size();

	while (l < r) {
		int mid = (l + r) / 2;

		if (index_list[mid] >= num)
			r = mid;
		else
			l = mid + 1;
	}
	return l;
}

int LIS() {
	for (int i = 0; i < n; i++) {
		int idx = get_index(stock[i]);

		if (idx < (int)index_list.size()) {
			index_list[idx] = stock[i];
		}
		else {
			index_list.push_back(stock[i]);
		}
	}
	return (int)index_list.size();
}

void init(){
	index_list.clear();
	cin >> n >> k;
	for (int i = 0; i < n; i++) {
		cin >> stock[i];
	}
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		init();
		
		cout << "Case #" << i << '\n';
		cout << (k <= LIS()) << '\n';
	}
}