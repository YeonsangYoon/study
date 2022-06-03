/**********************************************************************
작성일 : 2022-6-03
문제 :
	자동차경주 코스가 단방향 그래프로 주어진다. 
	이때, 1 -> 1로 가는 코스 중 가장 점수를 많이 얻는 코스를 구하라.
풀이 :
	위상정렬을 통해 단방향 그래프를 순회하였다.
	score, parent배열을 통해 각 지점의 최대점수와 직전노드를 기록하였다.

	parent에 기록된 정보를 토대로 코스를 역주행하여 vector에 저장하였다.
	역주행 코스를 reverse하여 올바른 코스를 구하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int score[1001], inDegree[1001], parent[1001];
struct edge {
	int e, cost;
};
vector<edge> adjList[1001];

vector<int> get_best_course() {
	queue<int> q;
	q.push(1);

	bool flag = false;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == 1) {
			if (flag) break;
			flag = true;
		}

		for (edge& next : adjList[now]) {
			if (score[next.e] < score[now] + next.cost) {
				score[next.e] = score[now] + next.cost;
				parent[next.e] = now;
			}

			if (--inDegree[next.e] == 0)
				q.push(next.e);
		}
	}

	int cur = 1;
	vector<int> ret;
	ret.push_back(cur);
	while (1) {
		cur = parent[cur];
		ret.push_back(cur);
		if (cur == 1)
			break;
	}
	reverse(ret.begin(), ret.end());
	return ret;
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int p, q, r;
		cin >> p >> q >> r;
		adjList[p].push_back({ q, r });
		inDegree[q]++;
	}
}

int main(void) {
	fastio;
	init();

	vector<int> course = get_best_course();

	cout << score[1] << '\n';
	for (int& i : course)
		cout << i << ' ';
}