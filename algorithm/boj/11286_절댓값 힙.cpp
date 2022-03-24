/**********************************************************************
작성일 : 2022-03-24
문제 :
	절대값이 작은 것을 저장하는 힙을 구현하라. 
	절대값이 같으면 작은 것이 더 우선이다.
풀이 :
	cmp함수를 직접 구현하여 HEAP을 구현함.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_HEAP_SIZE 100001
using namespace std;

int n;

struct HEAP {
	int sz = 0;
	int data[MAX_HEAP_SIZE] = { 0, };

	void init() { sz = 0; }
	bool empty() { return (sz == 0) ? true : false; }
	bool cmp(int a, int b) {
		a = data[a]; b = data[b];
		if (abs(a) == abs(b)) return a < b;
		return abs(a) < abs(b);
	}
	void push(int val) {
		data[sz] = val;

		int cur = sz++;
		while (cur > 0 && cmp(cur, (cur - 1) / 2)) {
			swap(data[cur], data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
	}
	int pop() {
		int ret = data[0];
		data[0] = data[--sz];

		int cur = 0;
		int child;
		while (cur * 2 + 1 < sz) {
			if (cur * 2 + 2 == sz)
				child = cur * 2 + 1;
			else
				child = (cmp(cur * 2 + 1, cur * 2 + 2)) ? cur * 2 + 1 : cur * 2 + 2;

			if (cmp(cur, child))
				break;

			swap(data[cur], data[child]);
			cur = child;
		}
		return ret;
	}
};
HEAP pq;

int main() {
	fastio;

	pq.init();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int num; cin >> num;

		if (num) {
			pq.push(num);
		}
		else {
			if (pq.empty()) {
				cout << 0 << '\n';
			}
			else {
				cout << pq.pop() << '\n';
			}
		}
	}
}