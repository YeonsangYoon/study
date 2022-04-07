/**********************************************************************
작성일 : 2022-04-07
문제 :
	두개의 문자열 a, b가 주어졌을 때 LCS(Longest Common Subsequence)를 구하라.
풀이 :
	dp와 memo를 이용하여 답을 구할 수 있다.
	dp[i][j] : a의 i번째, b의 j번째 문자까지의 LCS 길이
	
	이때 a의 i+1, b의 j+1번째 문자가 같다면 dp[i+1][j+1] = dp[i][j]+1이다.
	다르면, dp[i+1][j+1] = max(dp[i+1][j], dp[i][j+1])이다.

시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nm) (n : 문자열 a의 길이, m : 문자열 b의 길이)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string a, b;
int dp[1001][1001];

int get_lcs_len() {
	int aLen = (int)a.size();
	int bLen = (int)b.size();

	for (int i = 1; i <= aLen; i++) {
		for (int j = 1; j <= bLen; j++) {
			if (a[i - 1] == b[j - 1])
				dp[i][j] = dp[i - 1][j - 1] + 1;
			else
				dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
		}
	}
	return dp[aLen][bLen];
}

int main(void) {
	fastio;
	cin >> a >> b;

	cout << get_lcs_len();
}