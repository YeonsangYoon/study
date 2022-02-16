/**********************************************************************
작성일 : 2022-2-16
문제 :
	push, pop method를 가지는 최소 힙을 구현하라
풀이 :
	배열을 사용하는 hea을 구현함
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#define MAX_HEAP_SIZE 100001
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct HEAP {
	int size = 0;
	int data[MAX_HEAP_SIZE];

	void init() {
		size = 0;
	}
	void push(int value) {
		data[size] = value;

		int cur = size++;
		while (cur > 0 && data[(cur - 1) / 2] > data[cur]) {
			int tmp = data[cur];
			data[cur] = data[(cur - 1) / 2];
			data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
	}
	int pop() {
		if (size <= 0) return 0;

		int ret = data[0];
		data[0] = data[--size];

		int cur = 0;
		while (cur * 2 + 1 < size) {
			int child;
			if (cur * 2 + 2 == size)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1] < data[cur * 2 + 2]) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur] < data[child])
				break;

			int tmp = data[cur];
			data[cur] = data[child];
			data[child] = tmp;
			cur = child;
		}
		return ret;
	}
};

int main() {
	fastio;

	int n; cin >> n;
	HEAP heap;
	heap.init();

	for (int i = 0; i < n; i++) {
		int num; cin >> num;
		if (num == 0) {
			cout << heap.pop() << '\n';
		}
		else {
			heap.push(num);
		}
	}
}