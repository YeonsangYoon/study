/**********************************************************************
작성일 : 2022-07-25
문제 :
	숫자 n을 1, 2, 3의 합으로 나타내는 방법의 수를 구하라.
풀이 :
	dp와 메모이제이션을 이용하여, 시간복잡도를 O(n)으로 줄였다.
	또한, 여러번의 테스트케이스가 있기때문에 이전 쿼리에서 구했던 값을 사용하여 개선하였다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 1000000009
typedef long long ll;

int n, idx = 3;
ll dp[1000001];

int main(void) {
	fastio;

	dp[0] = 1; dp[1] = 1; dp[2] = 2;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n;

		if (dp[n] == 0) {
			for (int i = idx; i <= n; i++)
				dp[i] = (dp[i - 1] + dp[i - 2] + dp[i - 3]) % MOD;
			idx = n;
		}
		cout << dp[n] << '\n';
	}
}