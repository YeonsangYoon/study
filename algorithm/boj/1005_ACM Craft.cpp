/**********************************************************************
작성일 : 2022-01-13
문제 :
	각 건물을 짓기 위한 순서가 존재하고 그 순서는 매 게임마다 달라진다.
	또한, 각 건물은 해당 건물을 짓기 위한 고유의 delay가 존재한다. 
	이때 건물 w를 짓는 데 걸리는 최소 시간은?
풀이 :
	건물을 짓기 위한 커리큘럼이 존재하고 그 순서대로 건물을 지어야함
		=> 위상정렬 문제(ex. 교과과정, 스타크래프트 건물 짓는 순서)
	대신 이번에는 건물이 완공 되는 시간을 고려해야한다.
	어떠한 건물을 짓기 위해선 선행건물을 '모두' 지어야만 그때부터 건설 가능하다.
	따라서 그 건물의 완공시간은 바로 전 선행 건물의 완공시간의 최댓값에 자신의 delay 시간을 더한값이다.

	complete[i] = delay[i] + max(prevComplete time)
	
	이를 기록하면서 위상정렬을 수행하면 된다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n+k) (정점과 간선의 개수)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, k, w;		// n : 건물 개수, k : 순서 개수, w : 목표 건물
int delay[1001];	// 각 건물 건설 소요 시간
int complete[1001];	// 각 건물 완공 시간
int indegree[1001];	// 진입차수
vector<int> adjlist[1001];	// 간선리스트

void init() {
	// 이전 Test Case 값 지우기
	fill(delay, delay + 1001, 0);
	fill(complete, complete + 1001, 0);
	fill(indegree, indegree + 1001, 0);
	for (int i = 0; i <= 1000; i++) {
		vector<int>().swap(adjlist[i]);
	}

	// 입력 및 변수 초기화
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> delay[i];
	}
	for (int i = 0; i < k; i++) {
		int x, y;
		cin >> x >> y;
		indegree[y]++;
		adjlist[x].push_back(y);
	}
	cin >> w;
}
void solve() {
	// 위상정렬 수행
	queue<int> q;
	for (int i = 1; i <= n; i++) {
		if (indegree[i] == 0) {		// 진입차수 0인 것들 q에 push
			q.push(i);
			complete[i] = delay[i];
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		if (now == w) return;		// 목표인 w값을 구하면 그냥 종료

		for (int& next : adjlist[now]) {
			complete[next] = max(complete[next], complete[now] + delay[next]);
			if (--indegree[next] == 0)
				q.push(next);
		}
	}
}

int main() {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();		// 입력
		solve();	// 문제 풀이
		cout << complete[w] << "\n";	// 출력
	}
}