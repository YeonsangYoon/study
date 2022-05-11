/**********************************************************************
작성일 : 2022-5-11
문제 :
	대학교의 과목들과 각 과목들의 선수과목 관계가 주어진다.
	이때, 모든 과목에 대해 각 과목을 이수하기 위해 최소 몇학기가 걸리는 지 구하라.
풀이 :
	전형적인 위상정렬을 사용해야하는 문제이다. 
	단방향 그래프가 주어지고 이를, 순회하는 알고리즘이 필요했다. 
시간 제한 : 5초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int wTime[1001];
int inDegree[1001];
vector<int> adjlist[1001];

void set_time() {
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			q.push(i);
			wTime[i] = 1;
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			wTime[next] = max(wTime[next], wTime[now] + 1);
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		inDegree[b]++;
	}
}

int main(void) {
	fastio;
	init();
	set_time();

	for (int i = 1; i <= n; i++)
		cout << wTime[i] << ' ';
}