/**********************************************************************
작성일 : 2022-3-05
문제 :
	배열의 첫번째 원소를 버리는 Delete, 배열의 방향을 바꾸는 Reverse 명령어가 있다.
	명령어 string을 순차대로 실행한 결과를 출력하고 에러 발생시 error를 출력하라
풀이 :
	현재 순방향인지 역방향인지 mode 변수를 통해 관리한다.
	현재 mode에 따라 delete, print를 다르게 수행하도록 설계했다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n+p)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 100001
#define FORWARD 0
#define REVERSE 1
using namespace std;

int n, mode;
int l, r;
int arr[MAX];
string arrStr, cmdStr;

void set_reverse() {
	mode = (mode + 1) % 2;
}
int delete_element() {
	if (l > r) return -1;

	if (mode == FORWARD)
		l++;
	else if (mode == REVERSE)
		r--;
	return 1;
}
int excute() {
	for (char& c : cmdStr) {
		if (c == 'R') {
			set_reverse();
		}
		else {
			if (delete_element() == -1) {
				return -1;
			}
		}
	}
	return 1;
}

void init() {
	cin >> cmdStr >> n >> arrStr;

	int idx = 0;
	string tmp = "";
	for (char& c : arrStr) {
		if (c == '[' || c == ']' || c == ',') {
			if ((int)tmp.size() > 0) {
				arr[idx++] = stoi(tmp);
			}
			tmp = "";
		}
		else {
			tmp.push_back(c);
		}
	}

	l = 0;
	r = n - 1;
	mode = FORWARD;
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		init();

		if (excute() == -1) {
			cout << "error\n";
		}
		else {
			cout << '[';
			if (mode == FORWARD) {
				for (int i = l; i <= r; i++) {
					cout << arr[i];
					if (i != r)
						cout << ',';
				}
			}
			else if (mode == REVERSE) {
				for (int i = r; i >= l; i--) {
					cout << arr[i];
					if (i != l)
						cout << ',';
				}
			}
			cout << "]\n";
		}
	}
}