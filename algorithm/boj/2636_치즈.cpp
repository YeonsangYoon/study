/**********************************************************************
작성일 : 2022-1-21
문제 :
	매시간 치즈의 겉부분이 녹아내려 없어진다고 했을 때 
	치즈가 완전히 녹는데 걸린 시간과 바로 직전 치즈가 점유하고 있는 칸의 개수
풀이 :
	치즈의 겉면을 구하는 것을 구하는 것을 bfs를 수행하여 구하였다. 
	치즈로 둘러쌓인 구멍과 접촉한 치즈는 녹지 않는다. 
	따라서 치즈를 기준으로 bfs를 수행하지 않고 공기를 기준으로 수행하면서 공기와 맞닿은 치즈만 없애주었다.
	
	key point - 판의 가장자리는 반드시 치즈가 없고 공기만 있기 때문에 공기는 반드시 bfs 한 사이클 내에 순회 가능
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;	// n : 세로, m : 가로
int board[101][101];
int visited[101][101];
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 };

void input() {
	// 입력 값 받기
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j];
		}
	}
}
int get_piece_count() {
	// 조각 개수 count
	int cnt = 0;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == 1)
				cnt++;
		}
	}
	return cnt;
}
void melt_cheese() {
	// visited 초기화
	for (int i = 0; i < n; i++)
		for (int j = 0; j < m; j++)
			visited[i][j] = 0;

	// bfs(시작 노드 : (0, 0))
	queue<pair<int, int>> q;
	q.push(make_pair(0, 0));
	visited[0][0] = 1;

	while (!q.empty()) {
		int y = q.front().first;
		int x = q.front().second;
		q.pop();
		
		for (int i = 0; i < 4; i++) {
			int ny = y + dy[i];
			int nx = x + dx[i];

			if (ny < 0 || ny >= n || nx < 0 || nx >= m)
				continue;
			else if (visited[ny][nx] == 1 || board[ny][nx] == -1)
				continue;
			else if (board[ny][nx] == 1) {
				board[ny][nx] = -1;
				continue;
			}
			visited[ny][nx] = 1;
			q.push(make_pair(ny, nx));
		}
	}
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (board[i][j] == -1)
				board[i][j] = 0;
		}
	}
}
pair<int, int> solve() {
	int time = 0;
	int prev = get_piece_count();
	int cnt = prev;	

	while (cnt > 0) {		// 치즈가 있으면 다음 사이클 수행
		prev = cnt;			// 현재 치즈 칸수 저장
		melt_cheese();		// 겉면 제거
		cnt = get_piece_count();	// 겉면 제거 후 치즈 칸 수 count
		time++;
	}

	return make_pair(time, prev);
}

int main() {
	fastio;

	input();
	pair<int, int> retval = solve();

	cout << retval.first << '\n' << retval.second;

	return 0;
}