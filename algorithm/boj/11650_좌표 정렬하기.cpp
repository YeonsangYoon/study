/**********************************************************************
작성일 : 2022-8-19
문제 :
	N개의 좌표가 주어질 때, 이를 정렬하여 출력하라.
	정렬은 x좌표, y좌표 순으로 정렬한다.
풀이 :
	pair를 이용하여 정렬하였다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<pair<int, int>> dots;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int x, y;
		cin >> x >> y;
		dots.push_back({ x, y });
	}
}

int main(void) {
	fastio;
	init();

	sort(dots.begin(), dots.end());

	for (auto &dot : dots) {
		cout << dot.first << ' ' << dot.second << '\n';
	}
}