/*
* 1. 현재 들고있는 열쇠로 문 제거
* 2. 열쇠 줍기
* 3. 주운 열쇠가 없으면 종료
* 4. 이제 훔친다.
*/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

struct pos {
	int r, c;
};

int h, w;
bool visited[101][101];
char building[101][101];
queue<char> key;



void init_testcase() {
	cin >> h >> w;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> building[i][j];
		}
	}
	string s; cin >> s;
	for (char& c : s)
		key.push(c);
}

int main(void) {
	fastio;
	int tc; cin >> tc;

	for (int i = 0; i < tc; i++) {
		init_testcase();
	}
}