/**********************************************************************
작성일 : 2022-01-14
문제 :
	주어진 돈을 가지고 숫자를 구매한 다음 이를 통해 만들 수 있는 수의 최대값
풀이 :
	일단 이 문제는 상당히 예외처리를 하는 것에 대해 상당히 까다로웠음
	같은 수를 여러번 살 수 있기 때문에 사실상 최대값을 만드는 것은 최대한 많은 수를 사야함

	=> 어떻게 하면 많은 수를 살 수 있을까? => 가장 싼것만 사자!
	이때 두 가지 의문점이 든다.
	1. 만약 가장 싼게 0이면?
		- 살 수 있는 카드가 0 하나
		- 0 이외에 다른 카드가 있지만 돈이 없어서 0밖에 사지 못함
		- 0 이외에 다른 카드도 있고 돈도 있어서 살 수 있음
	2. 가장 싼 것만 사지 않아도 같은 수만큼 살 수 있으면?
	이는 가장 윗 자리수부터 돈이 여유가 되는 만큼 최대한 큰 수로 바꿔주는 것으로 해결할 수 있다.(grid)

	그리디한 방법과 철저한 예외처리를 통해 문제를 해결했다. 
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(logn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
int price[10];

struct card {
	int num, cost;
};
bool cmp(card& a, card& b) {
	if (a.cost == b.cost)
		return a.num > b.num;
	return a.cost < b.cost;
}
vector<card> cards;

void init() {
	// 입력 및 변수 초기화
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> price[i];
		cards.push_back({ i, price[i] });
	}
	cin >> m;
}

void solve() {
	sort(cards.begin(), cards.end(), cmp);  // 정렬

	int digits = 0;		// 가능한 최대수의 자리수
	int numbers[51];	// 만드는 숫자 배열

	if (n == 1) {	
		// 카드가 0번 한 장인 경우
		cout << 0;
		return;
	}
	else if (cards[0].num == 0 && cards[1].cost > m) {
		// 가장 싼 카드가 0이면서 그 윗 카드는 사지 못하는 경우
		cout << 0;
		return;
	}
	else if (cards[0].num == 0) {
		// 가장 싼 카드가 0이면서 그 윗카드도 구매 가능한 경우
		digits = 1 + (m - cards[1].cost) / cards[0].cost;
		numbers[0] = cards[1].num;
		m -= cards[1].cost;
		for (int i = 1; i < digits; i++) {
			numbers[i] = 0;
			m -= price[0];
		}
	}
	else {
		// 가장 싼 카드가 0이 아닌 경우
		digits = m / cards[0].cost;
		for (int i = 0; i < digits; i++) {
			numbers[i] = cards[0].num;
			m -= cards[0].cost;
		}
	}
	// 가장 큰 자리수부터 가능한 최대수로 교체
	for (int i = 0; i < digits; i++) {
		for (int j = n - 1; j > numbers[i]; j--) {
			if (m >= price[j] - price[numbers[i]]) {
				m -= price[j] - price[numbers[i]];
				numbers[i] = j;
				break;
			}
		}
	}
	// 수 출력
	for (int i = 0; i < digits; i++) cout << numbers[i];
}

int main() {
	fastio;

	init();
	solve();
}