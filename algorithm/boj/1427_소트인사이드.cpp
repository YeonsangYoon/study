/**********************************************************************
작성일 : 2022-8-25
문제 :
	배열을 정렬하는 것은 쉽다.
	수가 주어지면, 그 수의 각 자리수를 내림차순으로 정렬해보자.
풀이 :
	단순 정렬
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

vector<int> number;

void init() {
	string n;
	cin >> n;
	for (char& c : n) {
		number.push_back('0' - c);
	}
}

int main(void) {
	fastio;
	init();

	sort(number.begin(), number.end());

	for (int& i : number)
		cout << -i;
}