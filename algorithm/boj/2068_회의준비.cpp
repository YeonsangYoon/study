/**********************************************************************
작성일 : 2022-5-29
문제 :
	n명의 사람들이 있을 때 서로 알고있는 사람끼리 위원회를 구성한다고 한다.
	이때, m개의 관계가 주어질 때 각 위원회의 수와 각 위원회의 대표를 오름차순으로 출력하라.
	
	1. 서로 알고 있는 사람은 반드시 같은 위원회에 속해야 한다.
	2. 효율적인 회의 진행을 위해 위원회의 수는 최대가 되어야 한다.
풀이 :
	모든 쌍의 최단거리를 구해야하기 때문에 플로이드 워셜을 사용하여 각 최단거리를
	adjArr에 저장하였다.
	또한, 각 위원회를 서로소 집합으로 보고 union find 자료구조를 사용하여 구현하였다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define INF 10000000
using namespace std;

int n, m;
int adjArr[101][101];

struct disJointSet {
	int parent[101];

	void init() {
		for (int i = 1; i <= n; i++)
			parent[i] = i;
	}
	int find(int a) {
		if (a == parent[a]) return a;
		return parent[a] = find(parent[a]);
	}
	void merge(int a, int b) {
		a = find(a); b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
	int get_set_count() {
		set<int> s;
		for (int i = 1; i <= n; i++)
			s.insert(find(i));
		return (int)s.size();
	}
	vector<int> get_leaders() {
		vector<int> v;
		int distArr[101];
		int leaders[101];
		for (int i = 1; i <= n; i++) {
			distArr[i] = INF;
			leaders[i] = -1;
		}

		for (int i = 1; i <= n; i++) {
			int dist = 0;
			for (int j = 1; j <= n; j++) {
				if (i != j && find(i) == find(j)) {
					dist = max(dist, adjArr[i][j]);
				}
			}
			if (distArr[find(i)] > dist) {
				distArr[find(i)] = dist;
				leaders[find(i)] = i;
			}
		}

		for (int i = 1; i <= n; i++)
			if (leaders[i] != -1)
				v.push_back(leaders[i]);
		sort(v.begin(), v.end());
		return v;
	}
};
disJointSet djs;

void floyd() {
	for (int k = 1; k <= n; k++) {
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				adjArr[i][j] = min(adjArr[i][j], adjArr[i][k] + adjArr[k][j]);
			}
		}
	}
}

void init() {
	cin >> n >> m;

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (i == j)
				adjArr[i][j] = 0;
			else
				adjArr[i][j] = INF;
		}
	}

	djs.init();
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		adjArr[a][b] = adjArr[b][a] = 1;
		djs.merge(a, b);
	}
}

int main(void) {
	init();
	floyd();

	cout << djs.get_set_count() << '\n';

	vector<int> leaders = djs.get_leaders();
	for (int& leader : leaders)
		cout << leader << '\n';
}