/**********************************************************************
작성일 : 2022-04-09
문제 :
	이모티콘을 화면에 S개 띄우기 위한 최소 시간을 구하라.
	연산 1 - 화면에 있는 이모티콘을 클립보드에 저장한다.
	연산 2 - 클립보드에 있는 이모티콘을 화면에 복사한다.
	연산 3 - 화면에 있는 이모티콘 중 하나를 삭제한다.
풀이 :
	bfs를 통한 완전탐색을 수행하되 visited 배열을 통해 방문체크를 수행한다.
	이를 통해 중복으로 들어오는 것을 줄일 수 있다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int s;
bool visited[10000][10000];
struct state {
	int cnt, t, clipboard;
};

int bfs() {
	queue<state> q;
	q.push({ 1, 0, 0 });
	visited[1][0] = true;

	while (!q.empty()) {
		state now = q.front(); q.pop();

		if (!visited[now.cnt][now.cnt]) {
			q.push({ now.cnt, now.t + 1, now.cnt });
			visited[now.cnt][now.cnt] = true;
		}

		if (now.clipboard > 0 && !visited[now.cnt + now.clipboard][now.clipboard]) {
			if (now.cnt + now.clipboard == s)
				return now.t + 1;
			q.push({ now.cnt + now.clipboard, now.t + 1, now.clipboard });
			visited[now.cnt + now.clipboard][now.clipboard] = true;
		}
		if (now.cnt > 0 && !visited[now.cnt - 1][now.clipboard]) {
			if (now.cnt - 1 == s)
				return now.t + 1;
			q.push({ now.cnt - 1, now.t + 1, now.clipboard });
			visited[now.cnt - 1][now.clipboard] = true;
		}
	}
}

int main(void) {
	fastio;

	cin >> s;
	cout << bfs();
}