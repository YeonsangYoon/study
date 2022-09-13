#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, k;
int Left[2001], Right[2001];
int Lidx[2001], Ridx[2001];
vector<int> link, indexList;
vector<int> adjlist[2001];

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
	for (int i = 0; i < (int)link.size(); i++ ) {
		int idx = get_idx(link[i]);

		if (idx < (int)indexList.size())
			indexList[idx] = link[i];
		else
			indexList.push_back(link[i]);
	}
	return (int)indexList.size();
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> Left[i];
		Lidx[Left[i]] = i;
	}
	for (int i = 0; i < m; i++) {
		cin >> Right[i];
		Ridx[Right[i]] = i;
	}
	cin >> k;
	for (int i = 0; i < k; i++) {
		int l, r;
		cin >> l >> r;
		adjlist[l].push_back(r);
	}
	for (int l = 0; l < n; l++) {
		for (int& r : adjlist[Left[l]]) {
			link.push_back(Ridx[r]);
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << k - LIS();
}