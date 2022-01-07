/**********************************************************************
작성일 : 2022-01-07
작성자 : 윤연상
문제 :
	BOJ 15998 카카오머니
	LOG 유효성 검사
풀이 :
	굉장히 지문이 긴 전형적인 카카오 문제였음. 
	이번에도 굉장히 많이 틀렸는데 지문을 정확히 파악하지 않은 것에서 실수가 나왔음
	사실 이런 문제는 알고리즘적인 것보다 구현, 예외처리에 대한 스킬이 더 중요한 것같음

	(입출금 금액, 거래 후 잔액)의 형태를 가지는 log를 분석해서 유효성 검사를 하도록 유도했다.
	문제 유형이 뭔가 실무에서 나올 법한 내용임 
	
	=>  실제 정답 여부로 코드를 판단하는 것이 아니라 구현과정에서 올바른 결과를 내놓을지에 대한 
	검증이 필요해보임
시간 제한 : 5초
메모리 제한 : 256MB
예상 시간복잡도 : O(n + m)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef long long ll;

int n;			// log 개수
ll m;			// 최소충전금액
ll minm;		// 최소충전금액의 최소값
ll previous;	// 거래 전 잔액

ll gcd(ll a, ll b) {
	while (1) {
		if (b == 0)
			return a;
		ll r = a % b;
		a = b;
		b = r;
	}
	return a;
}
ll solve(int n) {
	bool flag = false;	// 한번이라도 충전 했는지 여부 
	
	for (int i = 0; i < n; i++) {
		// a : 입출금 금액, b : 거래 후 잔액, recharge : 충전금액
		// recharge = b - a - previous
		ll a, b; cin >> a >> b;
		ll recharge = b - a - previous;

		if (a > 0) {
			if (recharge != 0) {
				return -1;
			}
		}
		else if (a < 0) {
			if (recharge > 0) {
				if (!flag) {
					m = recharge;
					minm = b;
					flag = true;
				}
				else {
					m = gcd(m, recharge);
					minm = max(minm, b);
				}
			}
			else if (recharge < 0) {
				return -1;
			}
		}
		previous = b;
	}
	if (!flag) {	// 한번도 충전 안했을 경우
		return 1;
	}
	else if (m > minm) {
		return m;
	}
	else {
		return -1;
	}
}

int main(void) {
	fastio;

	cin >> n;
	cout << solve(n);

	return 0;
}