/**********************************************************************
작성일 : 2022-05-17
문제 :
	하천계가 유향그래프로 주어진다. 하천계의 Strahler 순서는 다음과 같다.
	강의 근원인 노드의 순서는 1이다.
	나머지 노드는 그 노드로 들어오는 강의 순서 중 가장 큰 값을 i라 할 때,
	들어오는 i의 개수가 1개이면 해당 노드의 순서는 i, 2개 이상이면 순서는 i+1이다.

	이때, 하천계의 순서인 노드 m의 순서를 구하라.
풀이 :
	유향 그래프를 순서대로 순회하기 위해 위상정렬 알고리즘을 사용하였다.
	각 노드의 i의 개수를 cnt 배열에, i의 값을 maxOrder에, 최종적인 순서를 order배열에 저장하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int k, m, p;
int inDegree[1001];
int order[1001], cnt[1001], maxOrder[1001];
vector<int> adjlist[1001];

void set_order() {
	queue<int> q;
	for (int i = 1; i <= m; i++) {
		if (inDegree[i] == 0) {
			order[i] = 1;
			q.push(i);
		}
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();
		order[now] = (cnt[now] == 1) ? maxOrder[now] : maxOrder[now] + 1;

		for (int& next : adjlist[now]) {
			if (order[now] > maxOrder[next]) {
				cnt[next] = 1;
				maxOrder[next] = order[now];
			}
			else if (order[now] == maxOrder[next]) {
				cnt[next]++;
			}

			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

void input() {
	cin >> k >> m >> p;
	for (int i = 0; i < p; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		inDegree[b]++;
	}
}

void init() {
	memset(inDegree, 0, sizeof(inDegree));
	memset(order, 0, sizeof(order));
	memset(cnt, 0, sizeof(cnt));
	memset(maxOrder, 0, sizeof(maxOrder));
	for (int i = 1; i <= 1000; i++) {
		adjlist[i].clear();
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	for (int i = 1; i <= tc; i++) {
		init();
		input();
		set_order();

		cout << k << ' ' << order[m] << '\n';
	}
}