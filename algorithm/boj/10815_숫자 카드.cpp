/**********************************************************************
작성일 : 2022-7-21
문제 :
	n개의 숫자카드에서 m개의 수가 있는 지 확인한다.
	만약 해당 숫자가 있으면 1을 아니면 0을 출력하라
풀이 :
	숫자카드의 개수 n의 최대값은 500000이고, 쿼리의 최대 개수는 500000이다.
	따라서 각 쿼리의 시간복잡도는 O(n)보다 작아야한다.
	이분탐색을 활용하여 해당 조건을 만족하였다.
시간 제한 : 2초
메모리 제한 : 256MB
예상 시간복잡도 : O(mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX 500001

int n, m;
int cards[MAX];

int binary_search(int num) {
	int l = 0, r = n - 1;
	
	while (l <= r) {
		int mid = (l + r) / 2;

		if (cards[mid] == num)
			return 1;
		else if (cards[mid] > num)
			r = mid - 1;
		else
			l = mid + 1;
	}
	return 0;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> cards[i];
	sort(cards, cards + n);
}

int main(void) {
	fastio;
	init();

	int q; cin >> q;
	for (int i = 0; i < q; i++) {
		int num; cin >> num;
		cout << binary_search(num) << ' ';
	}
}