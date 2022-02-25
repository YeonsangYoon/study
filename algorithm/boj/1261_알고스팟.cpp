/**********************************************************************
작성일 : 2022-2-25
문제 :
	2차원 미로에서 최단거리로 가기 위해 뚫어야하는 벽의 최소 개수를 구하라.
풀이 :
	heap과 dijkstra를 구현하여 풀이함
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 101
#define INF 10000000
using namespace std;

int n, m;
int maze[MAX][MAX];
int dist[MAX][MAX];
int dx[4] = { 0, 0, 1, -1 };
int dy[4] = { 1, -1, 0, 0 };

struct node {
	int y, x, dist;
};
struct HEAP {
	int size;
	node data[MAX * MAX];
	
	void init() { size = 0; }
	void push(node val) {
		data[size] = val;
		int cur = size++;

		while (cur > 0 && data[cur].dist < data[(cur - 1) / 2].dist) {
			node tmp = data[cur];
			data[cur] = data[(cur - 1) / 2];
			data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
	}
	node pop() {
		node ret = data[0];
		data[0] = data[--size];

		int cur = 0;
		int child;
		while (cur * 2 + 1 < size) {
			if (cur * 2 + 2 == size)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1].dist < data[cur * 2 + 2].dist) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur].dist < data[child].dist) break;
			node tmp = data[cur];
			data[cur] = data[child];
			data[child] = tmp;
			cur = child;
		}
		return ret;
	}
};
HEAP heap;

void init() {
	cin >> m >> n;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		for (int j = 1; j <= m; j++) {
			maze[i][j] = s[j - 1] - '0';
		}
	}
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			dist[i][j] = INF;
		}
	}
}
int solve() {
	heap.init();
	heap.push({ 1, 1, 0 });
	dist[1][1] = 0;

	while (heap.size > 0) {
		node now = heap.pop();

		if (now.dist > dist[now.y][now.x]) continue;

		for (int i = 0; i < 4; i++) {
			int ny = now.y + dy[i];
			int nx = now.x + dx[i];
			int nd = (maze[ny][nx]) ? now.dist + 1 : now.dist;

			if (nd < dist[ny][nx]) {
				dist[ny][nx] = nd;
				heap.push({ ny, nx, nd });
			}
		}
	}
	return dist[n][m];
}

int main() {
	fastio;

	init();
	cout << solve();
}