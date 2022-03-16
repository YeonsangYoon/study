/**********************************************************************
작성일 : 2022-3-16
문제 :
	수열 각 원소의 오큰수를 구하라.
	오큰수는 오른쪽에 있으면서 자신보다 큰 수 중에서 가장 왼쪽에 있는 수를 의미한다.
풀이 :
	스택을 사용하여 연산 횟수를 줄인다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001
using namespace std;

int n;
int ans[MAX_SIZE];
struct node {
	int idx, data;
};
stack<node> st;

void init() {
	cin >> n;
}
void solve() {
	int element;
	cin >> element;
	st.push({ 0, element });

	for (int i = 1; i < n; i++) {
		cin >> element;
		while (!st.empty()) {
			node top = st.top();
			if (top.data < element) {
				st.pop();
				ans[top.idx] = element;
			}
			else {
				break;
			}
		}
		st.push({ i, element });
	}

	while (!st.empty()) {
		ans[st.top().idx] = -1;
		st.pop();
	}
}

int main() {
	fastio;

	init();
	solve();

	for (int i = 0; i < n; i++) {
		cout << ans[i] << ' ';
	}
}