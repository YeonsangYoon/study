/**********************************************************************
작성일 : 2022-7-04
문제 :
	일렬로 진열된 N개의 인형이 있고, 해당 인형들의 선호도가 주어진다.
	이때, 연속으로 진열된 K개 이상의 인형의 표준편차의 최솟값을 구하라.
풀이 :
	완전탐색으로 모든 경우를 계산할 시 최악의 경우(n = 500, k = 1) 2천만정도의 연산 횟수를 가진다.
	따라서 완전탐색으로 구현해도 무방하다.
	표준편차를 구하는 길이를 len 이라고 했을 때 len의 범위는 k ~ n이다.
	모든 경우의 len에 대하여 표준편차를 구하여 최솟값을 구하였다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_N 500
typedef long double ld;

int n, k, cnt;
int prefer[MAX_N];

ld get_stdev(int s, int e) {
	ld avg = 0;
	for (int i = s; i <= e; i++)
		avg += prefer[i];
	avg /= (e - s + 1);

	ld stdev = 0;
	for (int i = s; i <= e; i++) {
		stdev += (prefer[i] - avg) * (prefer[i] - avg);
	}
	stdev /= (e - s + 1);

	return sqrt(stdev);
}

void init() {
	cin >> n >> k;
	for (int i = 0; i < n; i++)
		cin >> prefer[i];
}

int main(void) {
	fastio;
	init();

	ld minVal = 10000000;
	for (int len = k; len <= n; len++) {
		for (int i = 0; i + len <= n; i++) {
			minVal = min(minVal, get_stdev(i, i + len - 1));
		}
	}

	cout.precision(11);
	cout << minVal;
}