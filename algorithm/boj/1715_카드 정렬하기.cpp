/**********************************************************************
작성일 : 2022-3-01
문제 :
	
풀이 :
	연결리스트를 구현하고 이를 통해 dfs를 수행하여 리프의 개수를 구한다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_HEAP_SIZE 100010
using namespace std;

int n;

struct HEAP {
	int size;
	int data[MAX_HEAP_SIZE];
	void init() { size = 0; }
	int top() { return data[0]; }
	void push(int val) {
		data[size] = val;

		int cur = size++;
		while (cur > 0 && data[cur] < data[(cur - 1) / 2]) {
			swap(data[cur], data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
	}
	int pop() {
		int ret = data[0];
		data[0] = data[--size];

		int cur = 0;
		int child;
		while (cur * 2 + 1 < size) {
			if (cur * 2 + 2 == size)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1] < data[cur * 2 + 2]) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur] < data[child])
				break;
			swap(data[cur], data[child]);
			cur = child;
		}
		return ret;
	}
};
HEAP heap;

int solve() {
	int ret = 0;
	while (heap.size > 1) {
		int c1 = heap.pop();
		int c2 = heap.pop();
		heap.push(c1 + c2);
		ret += (c1 + c2);
	}
	return ret;
}
void init() {
	heap.init();

	cin >> n;
	for (int i = 0; i < n; i++) {
		int card; cin >> card;
		heap.push(card);
	}
}

int main() {
	fastio;

	init();
	cout << solve();
}