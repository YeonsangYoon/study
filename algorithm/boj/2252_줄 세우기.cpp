/**********************************************************************
작성일 : 2022-1-22
문제 :
	n명의 학생이 있을 때, m번의 키 비교를 통해 모든 학생의 키 순서를 출력하라
	(여러 답안 가능)
풀이 :
	간단한 위상정렬 수행
	여러 답안 가능을 보면 힌트를 얻을 수 있다. 
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
int indegree[32001];
vector<int> adjlist[32001];

void init() {
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;	// a가 b앞에 서야한다.(a키 < b키)
		indegree[b]++;
		adjlist[a].push_back(b);
	}
}
void solve() {
	// 위상정렬
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		cout << now << ' ';

		for (int& nex : adjlist[now]) {
			if (--indegree[nex] == 0) {
				q.push(nex);
			}
		}
	}
}

int main() {
	fastio;

	init();
	solve();
}