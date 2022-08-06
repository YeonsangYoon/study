/**********************************************************************
작성일 : 2022-08-06
작성자 : 윤연상
문제 :
	수빈이와 동생의 위치가 주어졌을 때, 수빈이가 동생을 찾을 수 있는 
	가장 빠른 시간이 몇 초 후인지 구하는 프로그램을 작성하시오.
	만약, 수빈이의 위치가 X일 때 걷는다면 1초 후에 X-1 또는 X+1로 이동하게 된다. 
	순간이동을 하는 경우에는 1초 후에 2*X의 위치로 이동하게 된다.
풀이 :
	heap을 응용하여 값을 저장하는 dp배열을 갱신하는 경우에만 heap에 추가하였다.
	다익스트라를 응용한 알고리즘이다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 100000
#define INF 1000000000

struct node {
	int i, cnt;
	bool operator<(const node& a)const {
		return a.cnt < cnt;
	}
};

int n, k;
int dp[MAX + 1];

int solve() {
	priority_queue<node> pq;
	pq.push({ n, 0 });

	while (!pq.empty()) {
		node now = pq.top(); pq.pop();

		if (dp[now.i] < now.cnt) continue;

		if (now.i + 1 >= 0 && now.i + 1 <= MAX) {
			if (dp[now.i + 1] > now.cnt + 1) {
				dp[now.i + 1] = now.cnt + 1;
				pq.push({ now.i + 1, now.cnt + 1 });
			}
		}
		if (now.i - 1 >= 0 && now.i - 1 <= MAX) {
			if (dp[now.i - 1] > now.cnt + 1) {
				dp[now.i - 1] = now.cnt + 1;
				pq.push({ now.i - 1, now.cnt + 1 });
			}
		}
		if (now.i * 2 >= 0 && now.i * 2 <= MAX) {
			if (dp[now.i * 2] > now.cnt + 1) {
				dp[now.i * 2] = now.cnt + 1;
				pq.push({ now.i * 2, now.cnt + 1 });
			}
		}
	}
	return dp[k];
}

void init() {
	cin >> n >> k;
	for (int i = 0; i <= 100000; i++)
		dp[i] = INF;
	dp[n] = 0;
}

int main(void) {
	fastio;
	init();

	cout << solve();
}