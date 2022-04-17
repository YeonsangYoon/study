/**********************************************************************
작성일 : 2022-04-17
문제 :
	마약수사대 관련 문제이다. 마약공급책들은 서로에게 마약을 공급받는다.
	이러한 마약공급체들의 관계는 a -> b와 같은 단방향 그래프로 표현된다.
	
	'마약의 원산지'는 다른 공급책에게 공급받지 않으면서 마약을 공급하는 마약공급책이다.
	이때 경찰이 몇 명의 마약공급책을 검거했을 때 여전히 마약을 공급받는 마약공급책의 수를 구하라.
풀이 :
	단방향 그래프를 순회하는 문제이다. 따라서 dfs를 이용하여 문제를 해결했다.
	검거 당한 마약 공급책을 순회하지 않기 위해 visited 배열에 미리 true로 체크해주었다.

	또한, inDegree배열을 통해 마약의 원산지를 파악하였고, 마약의 원산지를 시작점으로
	dfs를 수행하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n+m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m, ans;
int inDegree[26];
bool visited[26];
vector<int> adjlist[26];

void dfs(int cur) {
	visited[cur] = true;
	if (inDegree[cur] != 0)
		ans++;

	for (int& next : adjlist[cur]) {
		if (!visited[next])
			dfs(next);
	}
}

void init() {
	cin >> n >> m;

	for (int i = 0; i < m; i++) {
		char a, b;
		cin >> a >> b;
		inDegree[b - 'A']++;
		adjlist[a - 'A'].push_back(b - 'A');
	}

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		char a; cin >> a;
		visited[a - 'A'] = true;
	}
}

int main(void) {
	fastio;
	init();

	for (int i = 0; i < n; i++) {
		if (inDegree[i] == 0 && !visited[i])
			dfs(i);
	}
	cout << ans;
}