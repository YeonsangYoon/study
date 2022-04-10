/**********************************************************************
작성일 : 2022-04-10
문제 :
	한 사람의 덩치는 키와 몸무게로 구성되어있다.
	덩치가 크다라고 하는 것은 키와 몸무게 모두 큰 경우를 말한다. 
	이때 각 사람의 덩치 등수를 구하라.
풀이 :
	사람의 수 N은 최대 50이기 때문에 완전탐색으로 충분히 구현가능하다.
	완전탐색은 O(n^2)의 시간복잡도를 가진다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^2)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
struct body {
	int w, h;
	bool operator>(const body a) const {
		if (a.w < w && a.h < h)
			return true;
		return false;
	}
};
body people[51];

int get_rank(int p) {
	int rank = 1;

	for (int i = 1; i <= n; i++) {
		if (people[i] > people[p])
			rank++;
	}
	return rank;
}

void init() {
	cin >> n;

	for (int i = 1; i <= n; i++) {
		int w, h;
		cin >> w >> h;
		people[i] = { w, h };
	}
}

int main(void) {
	fastio;
	init();

	for (int i = 1; i <= n; i++) {
		cout << get_rank(i) << ' ';
	}
	return 0;
}