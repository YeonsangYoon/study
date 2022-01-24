/**********************************************************************
작성일 : 2022-1-24
문제 :
	N*N 크기의 이차원배열에서 각 수는 반드시 자신의 한칸 위의 수보다 크다는 것이 보장될때
	전체 이차원배열에서 N번째 큰수를 찾아라
풀이 :
	1 ≤ N ≤ 1,500
	전체 크기는 N^2으로 2백만 정도 된다. 따라서 전체 수를 정렬(O(n^2logn^2))하면 TLE이다.
	따라서 heap을 이용하여 시간복잡도를 줄이고자 한다.
	전체 수를 heap에 넣을 필요 없이 가장 큰 수를 포함하고 있는 마지막 행을 넣는다.
	pop한 수의 바로 위를 pq에 계속 넣어줌으로써 heap안에 이차원배열의 가장 큰수가 있도록 유지시켜준다.
시간 제한 : 1초
메모리 제한 : 12MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int nums[1501][1501];
struct number {
	int y, x;
	int num;
};
struct cmp {
	bool operator()(number& a, number& b) {
		return a.num < b.num;
	}
};
priority_queue<number, vector<number>, cmp> pq;

void init() {
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> nums[i][j];
		}
	}
	// 마지막 행 heap에 push
	for (int i = 0; i < n; i++) {
		pq.push({ n - 1 , i, nums[n - 1][i] });
	}
}
int solve() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		number now = pq.top(); pq.pop();
		ret = now.num;
		pq.push({ now.y - 1, now.x, nums[now.y - 1][now.x] });
	}

	return ret;
}

int main() {
	fastio;

	init();
	cout << solve();
}