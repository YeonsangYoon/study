/**********************************************************************
작성일 : 2022-1-31
문제 :
	maxHeap 구현 (pop, push)
풀이 :
	arr 기반 heap 구현
	push, pop method 구현
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

class maxHeap {
private:
	int size;
	int ptr;
	int data[100001];
public:
	maxHeap() {
		size = 0;
		ptr = 0;
		memset(data, 0, sizeof(data));
	}
	void push(int x);
	int pop();
};
void maxHeap::push(int x) {
	size++;
	data[++ptr] = x;

	int child = ptr;
	int parent = ptr / 2;
	while (parent > 0) {
		if (data[parent] < data[child]) {
			swap(data[parent], data[child]);
			child = parent;
			parent = child / 2;
		}
		else {
			break;
		}
	}
}
int maxHeap::pop() {
	if (size == 0) return 0;

	size--;
	int ret = data[1];
	data[1] = data[ptr--];
	
	int parent = 1;
	int child = 2;
	while (child <= ptr) {
		if (child + 1 <= ptr) {
			child = (data[child] >= data[child + 1]) ? child : child + 1;
		}

		if (data[parent] < data[child]) {
			swap(data[parent], data[child]);
			parent = child;
			child = 2 * parent;
		}
		else {
			break;
		}
	}

	return ret;
}

maxHeap pq;

int main() {
	fastio;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		if (x)
			pq.push(x);
		else 
			cout << pq.pop() << '\n';
	}

	return 0;
}