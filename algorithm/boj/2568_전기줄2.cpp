#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int line[500001], index[100001];
bool used[500001];
vector<int> linked, indexList;

int get_index(int num) {
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
		int idx = get_index(linked[i]);
		index[i] = idx;

		if (idx < (int)indexList.size())
			indexList[idx] = linked[i];
		else
			indexList.push_back(linked[i]);
	}
	int idx = (int)indexList.size() - 1;
	for (int i = n - 1; i >= 0; i--) {
		if (index[i] == idx) {
			used[linked[i]] = true;
			idx--;
		}
	}
	return (int)indexList.size();
}

void init() {
	memset(used, false, sizeof(used));
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a, b;
		cin >> a >> b;
		line[a] = b;
	}
	for (int i = 1; i <= 500000; i++) {
		if (line[i])
			linked.push_back(line[i]);
	}
}

int main(void) {
	fastio;
	init();

	cout << n - LIS() << '\n';
	for (int i = 1; i <= 500000; i++) {
		if (!used[line[i]] && line[i]) {
			cout << i << '\n';
		}
	}
}