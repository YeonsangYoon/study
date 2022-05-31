/**********************************************************************
작성일 : 2022-5-31
문제 :
	n개의 사건과 k개의 사건의 전후 관계가 주어질 때 s개의 사건 쌍의 전후관계를 구하라.
풀이 :
	우선 간선이 단방향으로 주어진다.
	이를 인접행렬로 구현하고 '플로이드-워셜'을 사용하여 구하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10000000
using namespace std;

int n, k;
int adjArr[401][401];

void floyd() {
	for (int K = 1; K <= n; K++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adjArr[i][j] = min(adjArr[i][j], adjArr[i][K] + adjArr[K][j]);
			}
		}
	}
}

void init() {
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			adjArr[i][j] = (i == j) ? 0 : INF;
		}
	}
	for (int i = 0; i < k; i++) {
		int a, b;
		cin >> a >> b;
		adjArr[a][b] = 1;
	}
}

int main(void) {
	fastio;
	init();
	floyd();

	int s; cin >> s;
	for (int i = 0; i < s; i++) {
		int a, b;
		cin >> a >> b;

		if (adjArr[a][b] != INF)
			cout << -1 << '\n';
		else if (adjArr[b][a] != INF)
			cout << 1 << '\n';
		else
			cout << 0 << '\n';
	}
}