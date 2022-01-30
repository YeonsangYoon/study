/**********************************************************************
작성일 : 2022-1-30
문제 :
	줄어들지 않는 n자리 수의 개수를 구하라.
	숫자의 앞에 0이 있어도 가능하다(ex 0000, 0011)
풀이 :
	1 <= n <= 64 이기 때문에 dfs를 통한 완전탐색은 TLE가 발생
	따라서 계산량을 줄이기 위해 dp와 메모이제이션 활용
		- 현재 상태 정의 : x로 시작하는 n자리수
		- dp[x][n] = dp[x][n-1] + dp[x+1][n-1] + ... + dp[9][n-1]
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n + t)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

ll ans[65];
ll dp[10][65];

void solve() {
	// 1자리수 초기화
	for (int i = 0; i < 10; i++) {
		dp[i][1] = 1;
	}
	ans[1] = 10;

	// memoization
	for (int i = 2; i <= 64; i++) {
		ll tmp = 0;
		for (int j = 9; j >= 0; j--) {
			tmp += dp[j][i - 1];
			dp[j][i] = tmp;
			ans[i] += dp[j][i];
		}
	}

	// 정답 입출력
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		cout << ans[num] << '\n';
	}
}

int main() {
	fastio;
	solve();
	return 0;
}