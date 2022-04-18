/**********************************************************************
작성일 : 2022-04-18
문제 :
	암호는 C개의 후보 문자들 중 L개의 문자를 선택하여 오름차순으로 나열한 문자열이다.
	또한, 유효한 암호는 최소 한개의 암호와 최소 두개의 자음으로 구성되어 있다.
풀이 :
	후보문자의 최대 개수가 15개이기 때문에 완전탐색으로 풀이가 가능하다.
	c개의 후보문자 중 l개의 문자를 선택하는 조합문제이며 dfs를 이용하여 구현하였다.
	선택 완료 후 조건을 만족하는 지에 대해 검사하였다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nCl)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int l, c;
char alpa[16];
vector<char> selected;

bool isValid() {
	int vCnt = 0;
	int cCnt = 0;

	for (char& c : selected) {
		if (c == 'a' || c == 'e' || c == 'i' || c == 'o' || c == 'u')
			vCnt++;
		else
			cCnt++;
	}
	return vCnt >= 1 && cCnt >= 2;
}

void dfs(int cnt, int idx) {
	if (cnt == l) {
		if (isValid()) {
			for (char& c : selected)
				cout << c;
			cout << '\n';
		}
		return;
	}

	for (int i = idx; i < c; i++) {
		selected.push_back(alpa[i]);
		dfs(cnt + 1, i + 1);
		selected.pop_back();
	}
}

void init() {
	cin >> l >> c;
	for (int i = 0; i < c; i++) {
		cin >> alpa[i];
	}
	sort(alpa, alpa + c);
}

int main(void) {
	fastio;
	init();

	dfs(0, 0);
}