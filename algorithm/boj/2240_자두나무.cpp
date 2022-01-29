/**********************************************************************
작성일 : 2022-1-29
문제 :
	w번의 움직임으로 최대한 많이 줍고자 할 때 가질 수 있는 최대의 자두 개수
		1 ≤ T ≤ 1,000
		1 ≤ W ≤ 30
풀이 :
	현재 자리에 자두가 떨어지지 않는 경우 총 2가지의 선택이 가능하다.
		- 자리를 바꿔 자두를 줍거나
		- 자리를 바꾸지 않고 자두를 줍지 않는다.
	이를 완전탐색으로 구현하고자 하면 2^1000번 연산해야한다 => TLE
	따라서 메모이제이션을 통해 시간복잡도를 줄이고자 했다.
	점화식 - dp[curPos][w][time+1] = dp[curPos][w][time] (움직이지 않은 경우)
	       - dp[nextPos][w-1][time+1] = max(dp[nextPos][w-1][time+1], dp[curPos][w][time+1]+1) (움직인 경우)
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(t * w)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int t, w;
int dropOrder[1001];
int dp[3][31][1001];	// dp[현재위치][남은 움직임 횟수][현재시간] = 현재 가진 최대 자두 개수

void init() {
	// 입력
	cin >> t >> w;
	for (int i = 1; i <= t; i++) {
		cin >> dropOrder[i];
	}
	memset(dp, -1, sizeof(dp));
}
int solve() {
	dp[1][w][0] = 0;

	for (int time = 0; time < t; time++) {
		for (int i = 0; i <= w; i++) {
			for (int pos = 1; pos <= 2; pos++) {
				if (dp[pos][i][time] < 0)
					continue;
				int nextPos = dropOrder[time + 1];
				if (pos == nextPos) {	// 현재 위치에 자두가 떨어짐
					dp[pos][i][time + 1] = dp[pos][i][time] + 1;
				}
				else {		// 현재 위치에 자두가 떨어지지 않음
					if (i != 0) {	// 움직여서 자두를 줍는 경우
						dp[nextPos][i - 1][time + 1] = max(dp[nextPos][i - 1][time + 1], dp[pos][i][time] + 1);
					}				// 움직이지 않는 경우
					dp[pos][i][time + 1] = dp[pos][i][time];
				}
			}
		}
	}
	// w를 모두 소모해서 더이상 움직이지 못하는 경우와 시간이 t인 경우를 모두 비교
	int ret = 0;
	for (int pos = 1; pos <= 2; pos++) {
		for (int time = 1; time <= t; time++) {
			ret = max(ret, dp[pos][0][time]);
		}
		for (int i = 0; i <= w; i++) {
			ret = max(ret, dp[pos][i][t]);
		}
	}
	return ret;
}

int main() {
	fastio;

	init();
	cout << solve();

	return 0;
}