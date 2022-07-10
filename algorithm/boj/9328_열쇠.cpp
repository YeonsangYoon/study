#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int h, w;
char building[101][101];

void init_testcase() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> building[i][j];
		}
	}
}

int main(void) {
	fastio;
	int tc; cin >> tc;

	for (int i = 0; i < tc; i++) {
		init_testcase();
	}
}