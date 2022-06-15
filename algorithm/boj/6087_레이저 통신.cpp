/**********************************************************************
작성일 : 2022-6-15
문제 :
	W x H인 크기의 지도에서 c 에서 c로 레이저를 발사한다고 할 때,
	레이저를 회전시키기 위해 설치해야할 거울의 최소 개수를 구하라.
풀이 :
	거울 사용 횟수를 거리로 인식하여 다익스트라를 사용하였다.
	현재 상태를 정의하는 state 구조체를 정의하였고, 이를 이용하여 힙을 구현하였다.
	
	실수하기 쉬운 부분은 기존 다익스트라는 거리 비교시 같은 경우는 힙에 넣지 않지만,
	이 문제의 경우에는 거울 사용 횟수가 같더라도 방향이 다를 수 있기 때문에
	넣어야한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 1000000000
using namespace std;

int w, h;
int sr, sc, er, ec;
int dist[101][101];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
char Map[101][101];

struct state {
	int r, c, dir, cnt;
	bool operator<(const state& a) const {
		return a.cnt < cnt;
	}
};

void dijkstra() {
	priority_queue<state> pq;
	pq.push({ sr, sc, 0, 0 });
	pq.push({ sr, sc, 1, 0 });
	pq.push({ sr, sc, 2, 0 });
	pq.push({ sr, sc, 3, 0 });

	while (!pq.empty()) {
		state now = pq.top(); pq.pop();

		if (dist[now.r][now.c] < now.cnt)
			continue;

		for (int i = 0; i < 4; i++) {
			int nr = now.r + dr[i];
			int nc = now.c + dc[i];
			int ncnt = (i == now.dir) ? now.cnt : now.cnt + 1;

			if (nr < 0 || nr >= h || nc < 0 || nc >= w)
				continue;
			else if (Map[nr][nc] == '*')
				continue;
			
			if (dist[nr][nc] >= ncnt) {
				dist[nr][nc] = ncnt;
				pq.push({ nr, nc, i, dist[nr][nc] });
			}
		}
	}
}

void init() {
	cin >> w >> h;

	bool flag = true;
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			char c; cin >> c;
			Map[i][j] = c;

			if (c == 'C') {
				if (flag) {
					sr = i;
					sc = j;
					dist[i][j] = 0;
					flag = false;
				}
				else {
					er = i;
					ec = j;
					dist[i][j] = INF;
				}
			}
			else {
				dist[i][j] = INF;
			}
		}
	}
}

int main(void) {
	fastio;
	init();
	dijkstra();

	cout << dist[er][ec];
}