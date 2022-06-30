/**********************************************************************
작성일 : 2022-6-30
문제 :
	어떤 수열 S가 주어질 때, 최대공약수가 1이 되는 부분집합의 개수를 구하라.
풀이 :
	나이브하게 모든 부분집합을 확인하는 것은 2^50이므로 TLE이다.
	이를 개선하기 위해 dp와 메모이제이션을 활용하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 100000
#define MOD 10000003

int n;
int s[50];
int dp[101][MAX + 1];

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> s[i];
}

int solve() {
	for (int i = 0; i < n; i++)
		dp[i][s[i]] = 1;
	
	for (int i = 1; i < n; i++) {
		for (int j = 1; j <= MAX; j++) {
			dp[i][j] += dp[i - 1][j];
			dp[i][j] %= MOD;
		}
		for (int k = 1; k <= MAX; k++) {
			int g = gcd(s[i], k);
			dp[i][g] += dp[i - 1][k];
			dp[i][g] %= MOD;
		}
	}
	return dp[n - 1][1] % MOD;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}