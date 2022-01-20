#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int t;
int n;
int level[26][26];
char board[26][26];

void init() {
	cin >> n;
	for (int i = 1; i <= n; ++i) {
		for (int j = 1; j <= n; ++j) {
			cin >> board[i][j];
		}
	}
}
void solve() {
	pair<int, int> startPoint[4];

}

int main() {
	fastio;
	
	cin >> t;
	for (int tc = 1; tc <= t; ++tc) {
		init();

	}
	return 0;
}