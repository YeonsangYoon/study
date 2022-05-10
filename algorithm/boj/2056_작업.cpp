/**********************************************************************
작성일 : 2022-5-10
문제 :
	각 작업들을 완료하는 데 소요시간과 해당 작업을 수행하기 위한 선행작업이 주어진다.
	이때, 모든 작업을 완료하는 데 걸리는 최소 시간을 구하라.
풀이 :
	각 작업을 수행하기 위해 반드시 해야하는 선행작업이 있다.
	이는 여러 작업들이 단방향 그래프의 관계를 가진다고 할 수 있다. 
	모든 작업을 수행하는 것을 구현하기 위해 이러한 단방향 그래프를 순회하고자 했고,
	이를 위상정렬로 구현하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int wTime[10001];	// 각 작업들의 소요시간
int fTime[10001];	// 각 작업들의 종료시간
int inDegree[10001];		// 진입차수
vector<int> adjlist[10001];	// 단방향 그래프

int get_min_time() {
	int ret = 0;
	queue<int> q;

	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			fTime[i] = wTime[i];
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		ret = max(ret, fTime[now]);

		for (int& next : adjlist[now]) {
			fTime[next] = max(fTime[next], fTime[now] + wTime[next]);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
	return ret;
}

void init() {
	cin >> n;

	int cnt;
	for (int i = 1; i <= n; i++) {
		cin >> wTime[i] >> cnt;

		for (int j = 0; j < cnt; j++) {
			int v; cin >> v;
			adjlist[v].push_back(i);
			inDegree[i]++;
		}
	}
}

int main(void) {
	fastio;
	init();

	cout << get_min_time();
}