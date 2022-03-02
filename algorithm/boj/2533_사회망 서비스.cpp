/**********************************************************************
작성일 : 2022-3-02
문제 :
	모든 친구들이 얼리어답터일때 자신도 얼리어답터가 된다고 할때
	모든 트리의 노드를 얼리어답터로 만들기 위한 최소 얼리어답터의 개수를 구하라
풀이 :
	leaf의 부모를 얼리어답터로 설정한다.
	백트레킹을 통해 얼리어답터의 조부모를 얼리어답터로 설정한다.
시간 제한 : 3초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 1000001
using namespace std;

int n, ans = 0;
vector<int> adjlist[MAX];

void init() {
	cin >> n;
	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
}

bool dfs(int cur, int parent) {
	bool result = false;
	for (int& child : adjlist[cur]) {
		if (child != parent) {
			if (dfs(child, cur))
				result = true;
		}
	}
	
	if (result) ans++;
	return !result;
}

int main() {
	fastio;

	init();
	dfs(2, 0);
	cout << ans;
}