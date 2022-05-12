/**********************************************************************
작성일 : 2022-5-12
문제 :
	무게가 서로 다른 N개의 물건이 있다. 또한, 물건 무게의 비교결과가 총 m가지 있다.
	이때, 각 물건에 대해 서로 비교할 수 없는 물건의 개수를 출력하라.
풀이 :
	물건의 관계는 단뱡향 그래프로 표현할 수 있다.
	물건 a, b가 있을 때 두 물건을 비교가능하다라는 의미는 해당 그래프에서
	a -> b or b -> a로 가는 경로가 존재하는 경우이다.
	이때, 모든 물건의 관계에 대해 조사해야 하기때문에 플로이드 워셜을 사용하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n^3 + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10000000
using namespace std;

int n, m;
int dist[101][101];
vector<int> adjlist[101];

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				dist[i][j] = min(dist[i][j], dist[i][k] + dist[k][j]);
			}
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			dist[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[b].push_back(a);
		dist[b][a] = 1;
	}
}

int main(void) {
	fastio;
	init();
	floyd();

	for (int i = 1; i <= n; i++) {
		int cnt = 0;
		for (int j = 1; j <= n; j++) {
			if (i != j && dist[i][j] == INF && dist[j][i] == INF)
				cnt++;
		}
		cout << cnt << '\n';
	}
}