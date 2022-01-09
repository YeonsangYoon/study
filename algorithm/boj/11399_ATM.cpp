/**********************************************************************
작성일 : 2022-01-09
문제 :
	ATM을 사용하는 사람들이 기다리는 시간의 최소값
풀이 :
	누적합의 누적합이 최소가 되도록만들고 값을 구하는 문제임
	배열의 누적합의 누적합이 최소가 되는 경우는 오름차순으로 정렬되어 있는 경우이다.

	p1 < p2 < p3 < p4 일떄
	s1 = p1
	s2 = p1 + p2
	s3 = p1 + p2 + p3
	s4 = p1 + p2 + p3 + p4
	total = 4p1 + 3p2 + 2p3 + p4 
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
	fastio;

	int n; 
	int time[1001];		// 사람들의 대기 순서
	
	cin >> n;			// 입력
	for (int i = 0; i < n; i++) {
		cin >> time[i];
	}

	sort(time, time + n);	// 오름차순 정렬

	int sum = 0;		// 누적합
	int ret = 0;		// 누적합의 누적합

	for (int i = 0; i < n; i++) {
		sum += time[i];
		ret += sum;
	}

	cout << ret;
}