#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
map<int, bool> isIn;
vector<int> note2;

void init() {
	isIn.clear();
	note2.clear();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		isIn[num] = true;
	}
	cin >> m;
	for (int i = 0; i < m; i++) {
		int num; cin >> num;
		note2.push_back(num);
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

		for (int& num : note2) {
			if (isIn[num])
				cout << 1 << '\n';
			else
				cout << 0 << '\n';
		}
	}
}