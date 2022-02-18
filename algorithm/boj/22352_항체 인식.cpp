/**********************************************************************
작성일 : 2022-2-17
문제 :
	격자모양의 사진의 before와 after를 보고 백신을 맞았는지 판단해라
	한개의 격자에 백신을 놓으면 같은 데이터를 가지는 인접한 격자도 바뀐다.
풀이 :
	bfs를 통해 before와 after가 다른 부분 한 군데만 바꾼뒤 after와 before를 비교한다.

시간 제한 : 1초
메모리 제한 : 1024MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <queue>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 31

using namespace std;

int n, m;
int before[MAX][MAX];
int after[MAX][MAX];
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
struct Pos {
	int r, c;
};


void input() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> before[i][j];
		}
	}
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> after[i][j];
		}
	}
}
void inject() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before[i][j] != after[i][j]) {
				int bf = before[i][j];
				int af = after[i][j];

				queue<Pos> q;
				q.push({ i, j });
				before[i][j] = af;

				while (!q.empty()) {
					Pos now = q.front(); q.pop();

					for (int k = 0; k < 4; k++) {
						int nr = now.r + dr[k];
						int nc = now.c + dc[k];

						if (nr < 0 || nr >= n || nc < 0 || nc >= m)
							continue;
						else if (before[nr][nc] != bf)
							continue;

						before[nr][nc] = af;
						q.push({ nr, nc });
					}
				}
				return;
			}
		}
	}
}
bool isInject() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (before[i][j] != after[i][j])
				return false;
		}
	}
	return true;
}

int main() {
	fastio;

	input();
	inject();
	if (isInject())
		cout << "YES";
	else
		cout << "NO";
}
