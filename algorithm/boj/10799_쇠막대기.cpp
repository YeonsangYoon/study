/**********************************************************************
작성일 : 2022-7-07
문제 :
	쇠막대기와 이를 자르는 레이저를 괄호로 표현하고, 이를 문자열로 주어진다.
	이때, 쇠막대기가 몇 조각으로 분리되는 지 구하라.
풀이 :
	스택을 활용하여 현재의 쇠막대기 개수를 저장하고 레이저가 나오면 현재 개수를 더하고
	막대가 끝나면 1개를 더해주면서 개수를 구한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string s;
stack<char> st;

int main(void) {
	fastio;
	cin >> s;

	int cnt = 0;
	char prev = ' ';
	for (char& c : s) {
		if (c == '(') {
			st.push(c);
		}
		else {
			st.pop();
			if (prev == '(')
				cnt += (int)st.size();
			else
				cnt += 1;
		}
		prev = c;
	}

	cout << cnt;
}