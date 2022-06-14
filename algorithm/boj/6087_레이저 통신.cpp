#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int w, h;
int dist[101][101];
char Map[101][101];

struct state {
	int r, c, dir, cnt;
	bool operator<(const state& a) const {
		return a.cnt < cnt;
	}
};

void init() {
	cin >> w >> h;

	bool flag = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c; cin >> c;
			Map[i][j] = c;

			if (c == 'c') {
				if (flag) {

				}
				else {

				}
			}
		}
	}
}

int main(void) {
	fastio;
	init();

}