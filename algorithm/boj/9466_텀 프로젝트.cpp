/**********************************************************************
작성일 : 2022-3-12
문제 :
	1~n까지의 학생이 각자 프로젝트를 하고 싶은 팀원이 있을 때
	서로 원하는 팀원이 맞을 때 프로젝트 팀이 만들어진다. 이때 어느 팀에도
	속하지 않는 학생의 수를 구하라.
풀이 :
	유향 그래프에서 사이클을 찾는 알고리즘
	보통 dfs로 구현하지만, 위상정렬도 가능하기 때문에 위상정렬로 구했다.
	위상정렬 수행후, indegree가 0보다 큰 경우 사이클이다.
시간 제한 : 3초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 100010
using namespace std;

int n;
int inDegree[MAX_SIZE];
vector<int> adjlist[MAX_SIZE];


void init() {
	cin >> n;

	memset(inDegree, 0, sizeof(inDegree));
	for (int i = 1; i <= n; i++) {
		adjlist[i].clear();
	}

	for (int i = 1; i <= n; i++) {
		int id; cin >> id;
		adjlist[i].push_back(id);
		inDegree[id]++;
	}
}
void topological_sort() {
	// 위상정렬 
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			if (--inDegree[next] == 0) {
				q.push(next);
			}
		}
	}
}


int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();		// input 및 변수 초기화
		topological_sort();	// 위상정렬 수행

		// indegree가 0이상이면 사이클
		int cnt = 0;
		for (int i = 1; i <= n; i++) {
			if (inDegree[i] > 0)
				cnt++;
		}
		cout << n - cnt << '\n';
	}
}