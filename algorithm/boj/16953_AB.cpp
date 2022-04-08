/**********************************************************************
작성일 : 2022-04-08
문제 :
	숫자 A와 B가 주어졌을 때, A를 B로 바꾸는데 필요한 연산의 최소값에 1을 더한값을 구하라.
		연산 1 - 2를 곱한다.
		연산 2 - 1을 수의 가장 오른쪽에 추가한다.
풀이 :
	완전탐색을 통해 구한다. dfs를 이용하여 완전탐색을 구현하였다.

시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

ll a, b;
int ans = INT_MAX;

ll op1(ll num) {
	return num * 2;
}
ll op2(ll num) {
	return num * 10 + 1;
}

void dfs(int cnt, ll cur) {
	if (cur > b) {
		return;
	}
	else if (cur == b) {
		ans = min(ans, cnt);
		return;
	}

	dfs(cnt + 1, op1(cur));
	dfs(cnt + 1, op2(cur));
}

int main(void) {
	fastio;
	cin >> a >> b;

	dfs(0, a);

	if (ans == INT_MAX)
		cout << -1;
	else
		cout << ans + 1;
}