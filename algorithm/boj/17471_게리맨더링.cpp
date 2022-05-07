/**********************************************************************
작성일 : 2022-05-07
문제 :
	n개의 마을이 있을 때, 이를 2개의 선거구로 분리하고자 한다.
	선거구 내의 마을은 모두 연결되어 있어야 하며, 각 마을은 고유의 인구를 가지고 있다.
	이때, 두 개의 선거구의 인구차이를 최소로 하면서 분리하는 경우를 구하라.
풀이 :
	마을의 개수 n은 최대 10개이다. 따라서 마을을 분리하는 것을 완전탐색으로 구할 수 있다.
	combination을 구현하여, 1 ~ n-1개를 선택하는 경우를 구현하였다.
	또한 선택한 후 각 선거구 내의 마을이 서로 연결되어 있는지를 bfs를 구현하여 확인하였다.

	valid 조건에 모두 통과한 경우 각 선거구의 인구 차이를 계산한 후 ans와 비교하였다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O()
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int ans = INT_MAX;
int pCnt[11];
bool visited[11];
vector<int> adjlist[11];

bool isValid() {
	// 2개의 선거구가 서로 연결되어있는지 확인(bfs)
	int ts, fs;
	bool copyed[11];
	for (int i = 1; i <= n; i++) {
		copyed[i] = visited[i];
		if (visited[i])
			ts = i;
		else
			fs = i;
	}

	queue<int> q;
	q.push(ts);
	copyed[ts] = false;
	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			if (copyed[next]) {
				copyed[next] = false;
				q.push(next);
			}
		}
	}
	for (int i = 1; i <= n; i++) {
		if (copyed[i])
			return false;
	}

	for (int i = 1; i <= n; i++)
		copyed[i] = visited[i];
	q.push(fs);
	copyed[fs] = true;

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			if (!copyed[next]) {
				copyed[next] = true;
				q.push(next);
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		if (!copyed[i])
			return false;
	}
	return true;
}

void combination(int selected, int idx, int cnt) {
	// 조합(cnt만큼 선택)
	if (selected == cnt) {
		if (isValid()) {
			int t = 0, f = 0;
			for (int i = 1; i <= n; i++) {
				if (visited[i])
					t += pCnt[i];
				else
					f += pCnt[i];
			}
			ans = min(ans, abs(t - f));
		}
		return;
	}

	for (int i = idx; i <= n; i++) {
		visited[i] = true;
		combination(selected + 1, i + 1, cnt);
		visited[i] = false;
	}
}

void init() {
	// 변수 입력 및 초기화
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> pCnt[i];
	}
	for (int i = 1; i <= n; i++) {
		int cnt; cin >> cnt;
		for (int j = 0; j < cnt; j++) {
			int k; cin >> k;
			adjlist[i].push_back(k);
		}
	}
}

int main(void) {
	fastio;
	init();

	for (int i = 1; i <= n - 1; i++) {
		combination(0, 1, i);	// 1 ~ n - 1만큼 선택
	}

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans;
}