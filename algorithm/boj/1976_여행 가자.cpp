/**********************************************************************
작성일 : 2022-5-27
문제 :
	n개의 도시와 각 도시들이 연결된 정보가 2차원 배열로 주어진다.
	이때, 여행하고자 할 m개의 도시가 주어질 때 해당 도시들이 모두 연결되어있는지 구하라.
풀이 :
	각 도시들이 연결되어 있는 지를 서로소 집합으로 표현한다.
	간선정보를 입력받으면서 두 도시 사이에 간선이 존재하면 merge를 수행한다.
	
	m개의 도시가 모두 연결되어있는 지 확인하는 것은 첫번째 도시와 나머지 m-1개의 도시가
	연결되어있는 지 확인하면된다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;

struct disJointSet {
	int parent[201];
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
};
disJointSet djs;

bool isConnected() {
	int first; cin >> first;
	first = djs.find(first);
	for (int i = 0; i < m - 1; i++) {
		int city; cin >> city;
		if (first != djs.find(city))
			return false;
	}
	return true;
}

void init() {
	cin >> n >> m;
	djs.init();
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			int city; cin >> city;
			if (city == 1) 
				djs.merge(i, j);
		}
	}
}

int main(void) {
	fastio;
	init();

	if (isConnected())
		cout << "YES";
	else
		cout << "NO";
}