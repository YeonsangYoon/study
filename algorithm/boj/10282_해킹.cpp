/**********************************************************************
작성일 : 2022-04-12
문제 :
	네트워크 시설의 컴퓨터들은 바이러스 의존성이 존재한다. 
	어떤 컴퓨터 a가 다른 컴퓨터 b에 의존한다면, b가 감염될 시 일정시간 뒤 a도 감염된다.
	이러한 의존성 관계는 두 개의 컴퓨터 번호, 감염 시간으로 표현된다.

	첫 감염된 컴퓨터 c가 주어질 때 총 감염되는 컴퓨터 수, 마지막 컴퓨터가 감염되는 시간을 구하라.
풀이 :
	이러한 네트워크와 의존성 관계는 단방향 그래프로 표현한다. 
	그리고 각 컴퓨터가 감염되는 최초 시각을 다익스트라를 통해 구한다.(최단거리)

	다익스트라 수행 후 감염된 컴퓨터의 수와 마지막 감염 시각을 구한다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(dlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, d, c;
int infectTime[10001];
struct dependency {
	int c, s;
	bool operator<(const dependency& a) const {
		return a.s < s;
	}
};
vector<dependency> adjlist[10001];

void infect_computer() {
	// 컴퓨터를 감염시키는 함수(다익스트라)
	priority_queue<dependency> pq;
	pq.push({ c, 0 });

	infectTime[c] = 0;

	while (!pq.empty()) {
		dependency now = pq.top(); pq.pop();

		if (now.s > infectTime[now.c]) continue;

		for (dependency& nex : adjlist[now.c]) {
			if (infectTime[nex.c] > infectTime[now.c] + nex.s) {
				infectTime[nex.c] = infectTime[now.c] + nex.s;
				pq.push({ nex.c, infectTime[nex.c] });
			}
		}
	}
}

void init() {
	cin >> n >> d >> c;

	// data 초기화
	for (int i = 1; i <= n; i++) {
		infectTime[i] = INT_MAX;
		adjlist[i].clear();
	}
	infectTime[c] = 0;

	// 신규 data 입력
	for (int i = 0; i < d; i++) {
		int a, b, s;
		cin >> a >> b >> s;
		adjlist[b].push_back({ a, s });
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		init();	// 초기화
		infect_computer(); // 나머지 컴퓨터 감염

		// 감염된 컴퓨터 수, 마지막 감염 시간 계산
		int cnt = 0;
		int t = 0;
		for (int i = 1; i <= n; i++) {
			if (infectTime[i] != INT_MAX) {
				cnt++;
				t = max(t, infectTime[i]);
			}
		}
		cout << cnt << ' ' << t << '\n';
	}
}