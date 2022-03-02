/**********************************************************************
작성일 : 2022-3-02
문제 :
	트리 구조를 가지는 직급 체계에서 모든 직원에게 뉴스를 전하기 위한 최소 시간을 구하라
	직속상사가 부하에게 뉴스를 전달하는 데 걸리는 시간은 각 1분이다.
풀이 :
	dfs와 백트레킹을 통해 각 자식들의 소요시간을 구한뒤
	최대 소요시간을 가지는 자식부터 먼저 뉴스를 알려주는 방식으로 구했다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, root;
vector<int> adjlist[51];

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int p; cin >> p;
		if (p == -1)
			root = i;
		else
			adjlist[p].push_back(i);
	}
}
int dfs(int parent, int depth) {
	int cCnt = (int)adjlist[parent].size();
	if (cCnt == 0)
		return depth;

	vector<int> cntArr;
	for (int& child : adjlist[parent]) {
		cntArr.push_back(dfs(child, depth + 1));
	}
	sort(cntArr.begin(), cntArr.end());
	for (int i = 0; i < cCnt; i++)
		cntArr[i] = cntArr[i] + cCnt - 1 - i;
	
	int ret = 0;
	for (int i = 0; i < cCnt; i++)
		ret = max(ret, cntArr[i]);
	return ret;
}

int main() {
	fastio;

	init();
	cout << dfs(root, 0);
}