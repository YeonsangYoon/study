/**********************************************************************
작성일 : 2022-3-03
문제 :
	n개의 수업을 배정하기 위한 최소 강의실의 개수를 구하라
	각 수업의 시작시간과 종료시간이 주어진다.
풀이 :
	각 수업을 시작시간 기준으로 정렬하고 heap에 현재 강의실의 종료시간을 넣고
	가장 빠르게 끝나는 강의실을 기준으로 해당 수업을 넣을 수 있으면 갱신하고
	못하면 새로운 강의실을 추가한다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 200001
using namespace std;

int n;

struct lecture {
	int s, e;
	bool operator<(const lecture& a) const {
		return a.s > s;
	}
};
lecture schedule[MAX_SIZE];

class HEAP {
private:
	int heapsize;
	int data[MAX_SIZE];
public:
	void init() { heapsize = 0; }
	int size() { return heapsize; }
	int top() { return data[0]; }
	void push(int val) {
		data[heapsize] = val;
		int cur = heapsize++;
		while (cur > 0 && data[cur] < data[(cur - 1) / 2]) {
			swap(data[cur], data[(cur - 1) / 2]);
			cur = (cur - 1) / 2;
		}
	}
	int pop() {
		int ret = data[0];
		data[0] = data[--heapsize];
		
		int cur = 0;
		int child;
		while (cur * 2 + 1 < heapsize) {
			if (cur * 2 + 2 == heapsize)
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

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int s, e;
		cin >> s >> e;
		schedule[i] = { s, e };
	}
	sort(schedule, schedule + n);
}
int solve() {
	heap.init();
	heap.push(0);

	for (int i = 0; i < n; i++) {
		if (heap.top() <= schedule[i].s) {
			heap.pop();
			heap.push(schedule[i].e);
		}
		else {
			heap.push(schedule[i].e);
		}
	}
	return heap.size();
}

int main() {
	fastio;
	
	init();
	cout << solve();
}