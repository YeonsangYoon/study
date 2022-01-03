/**********************************************************************
작성일 : 2022-01-03
작성자 : 윤연상
문제 :
	n개의 성냥개비를 가지고 표현할 수 있는 최대, 최소의 수를 구하는 문제
	
풀이 :
	사실 처음에는 dfs와 그리디를 섞어서 푸는 방법으로 접근했다. 
	- n개의 성냥개비를 각 문자별 개수로 쪼갠 경우의 수를 dfs로 구하고 
	- 이를 최소, 최대 수로 변환하는 과정이다.
	=> 여기서 문제점은 최소값의 경우 최대자리수가 50까지 넘어가기 때문에 long long으로도 표현이 안된다.
	
	이 과정에서 나는 최대값은 항상 동일한 패턴을 가지는 것을 확인했고, 짝수/홀수를 나눠 쉽게 구현했다.

	하지만, 최소값을 해결하기 위해 문제를 다시 dp적 관점에서 바라보았다.
	예를 들어 내가 만약 10개의 성냥개비를 사용하여 값을 표현하려면 반드시 2자리수 이상으로 표현해야한다.
	(숫자별 최대 사용 개수가 7개)
	10개의 성냥개비로 표현하고자 하는 최소 값은 2개+8개 or 3개+7개 or 4개+6개 5개 + 5개일 것이다. 
	점화식으로 표현하면 dp[8] = min(dp[2]+dp[8], dp[3]+dp[7], dp[4]+dp[6], dp[5]+dp[5]) 이다.
	이러한 성질을 이용하여 dp[100]까지의 값을 미리 구하고 각 testcase마다 저장된 값을 사용하였다. 
시간 제한 : 0초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int tc, n;
int cnt[9] = { 0,0,1,7,4,2,0,8 };
ll minDP[101];

void initDP() {
	minDP[2] = 1;
	minDP[3] = 7;
	minDP[4] = 4;
	minDP[5] = 2;
	minDP[6] = 6;	// 사실 최소값은 0이지만 조건에 맞지 않기 때문에 6을 사용
	minDP[7] = 8;
	minDP[8] = 10;	// dp[6]의 경우를 고려하여 미리 계산

	for (int i = 9; i <= 100; i++) {
		minDP[i] = LLONG_MAX;			// 비교를 위한 최대값 설정
		for (int j = 2; j < 8; j++) {	// 새로운 숫자를 하나씩 추가해 나가는 과정
			minDP[i] = min(minDP[i], minDP[i - j] * 10 + cnt[j]);
		}
	}
}
void print_max_num(int n) {	// 최대값 계산
	if (n % 2) {
		cout << "7";
		for (int i = 0; i < n / 2 - 1; i++) {
			cout << "1";
		}
	}
	else {
		for (int i = 0; i < n / 2; i++) {
			cout << "1";
		}
	}
}

int main(void) {
	fastio;

	initDP();

	cin >> tc;
	for (int i = 0; i < tc; i++) {
		cin >> n;
		cout << minDP[n] << " ";
		print_max_num(n);
		cout << "\n";
	}
	return 0;
}