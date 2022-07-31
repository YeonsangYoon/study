/**********************************************************************
작성일 : 2022-07-31
작성자 : 윤연상
문제 :
	n개의 정수로 이루어진 수열에서 가장 큰 연속합을 구하라.
풀이 :
	나이브하게 구하면 n^2이기 때문에 dp와 메모이제이션을 통하여 구하였다.
	dp[i]를 i번째에서 끝나는 연속합들 중 가장 큰 값이라고 할 때 다음과 같은 점화식이 있다.
	dp[i] = max(dp[i-1]+arr[i], arr[i])이다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int arr[100001], dp[100001];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

int main(void) {
	fastio;
	init();

	dp[1] = arr[1];
	int ans = dp[1];

	for (int i = 2; i <= n; i++) {
		dp[i] = max(dp[i - 1] + arr[i], arr[i]);
		ans = max(ans, dp[i]);
	}

	cout << ans;
}