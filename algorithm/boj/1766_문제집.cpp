/**********************************************************************
작성일 : 2022-01-06
작성자 : 윤연상
문제 :
	1~N번까지 난이도 순서대로 출제된 문제집의 선행 문제 조건을 고려하고, 올바른 풀이 순서를 찾아라.
	선행 문제 조건 
		1. A B (A번 문제는 반드시 B번 문제보다 먼저 풀어야함)
		2. 가능하면 낮은 난이도를 먼저 풀어야함
풀이 :
	A보다 B를 반드시 먼저 해야한다라는 조건을 보고 바로 위상정렬을 떠올렸다.
	- 위상정렬 : 진입차수(indegree)가 0인 것들을 차례대로 지워가면서 순서를 결정하는 알고리즘
	- 추가 조건 : 가능하면 쉬운 문제부터 풀어야한다.

	기존의 위상정렬은 진입차수가 0인 것들을 큐에 넣어서 순서를 고려하지 않았지만, 
	2번 조건 때문에 minheap를 사용하여 항상 제일 쉬운 문제가 선택되도록 구현했다.
	시간복잡도는 n에서 nlogn으로 조금 느려지긴 했어도 n의 최대값이 32000이기 때문에 충분히 가능함.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
int inDegree[32001];
vector<int> adjlist[32001];

void init_condi() {		// 초기 조건 초기화
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);	// 간선 리스트
		inDegree[b]++;				// 진입차수
	}
}
vector<int> solve() {	// 위상정렬, 힙
	vector<int> ret;
	priority_queue<int, vector<int>, greater<int>> minHeap;
	
	for (int i = 1; i <= n; i++) {
		if (inDegree[i] == 0) {
			minHeap.push(i);
		}
	}

	while (!minHeap.empty()) {
		int now = minHeap.top();
		minHeap.pop();
		ret.push_back(now);

		for (int i = 0; i < (int)adjlist[now].size(); i++) {
			if (--inDegree[adjlist[now][i]] == 0) {
				minHeap.push(adjlist[now][i]);
			}
		}
	}
	return ret;
}

int main() {
	fastio;

	init_condi();
	vector<int> result = solve();

	for (int i = 0; i < (int)result.size(); i++) {
		cout << result[i] << " ";
	}

	return 0;
}