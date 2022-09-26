#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;

int n, m, k;
ll maps[101][101];
bool visited[101][101];
bool fixRoad[101][101][2];	// 0 : 가로, 1 : 세로

ll get_way_cnt(int r, int c) {
	if (r > n || c > m)
		return 0;
	else if (visited[r][c])
		return maps[r][c];
	else if (r == n && c == m)
		return 1;

	visited[r][c] = true;
	if (!fixRoad[r][c][1])
		maps[r][c] += get_way_cnt(r + 1, c);
	if (!fixRoad[r][c][0])
		maps[r][c] += get_way_cnt(r, c + 1);
	return maps[r][c];
}

void init() {
	memset(visited, false, sizeof(visited));
	memset(fixRoad, false, sizeof(fixRoad));
	cin >> n >> m >> k;

	for (int i = 0; i < k; i++) {
		int a, b, c, d;
		cin >> a >> b >> c >> d;
		if (a == c) {
			fixRoad[a][min(b, d)][0] = true;
		}
		else {
			fixRoad[min(a, c)][b][1] = true;
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << get_way_cnt(0, 0);
}