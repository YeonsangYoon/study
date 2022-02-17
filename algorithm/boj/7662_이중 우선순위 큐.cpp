/**********************************************************************
작성일 : 2022-2-16
문제 :
	최소값과 최대값을 동시에 관리하는 이중 우선순위 큐를 만들어라.
	k개의 연산을 수행후 큐에 남아있는 최대, 최소값 출력
풀이 :
	데이터와 삭제됬는 지 여부를 포함하는 구조체를 선언한뒤 
	이에 대한 max heap, min heap을 직접 구현했다. 만약 한쪽 heap에서 pop연산 수행시
	해당 포인터를 통해 isDelete = true로 바꿔주고 추후 해당 포인터가 pop될 경우 다시 pop하도록 설계함
시간 제한 : 6초
메모리 제한 : 256MB
예상 시간복잡도 : ?
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX_SIZE 1000001

using namespace std;

struct Node {
	int n;
	bool isDelete;
};
int ptr = 0;
Node pool[MAX_SIZE];

struct MINHEAP {
	int size = 0;
	Node* data[MAX_SIZE];

	void init() {
		size = 0;
	}
	void push(Node* value) {
		data[size] = value;
		int cur = size++;

		while (cur > 0 && data[cur]->n < data[(cur - 1) / 2]->n) {
			Node* tmp = data[cur];
			data[cur] = data[(cur - 1) / 2];
			data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
	}
	Node* pop() {
		Node* ret = data[0];
		data[0] = data[--size];
		
		int cur = 0;
		int child;
		while (cur * 2 + 1 <= size) {
			if (cur * 2 + 1 == size)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1]->n < data[cur * 2 + 2]->n) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur]->n < data[child]->n)
				break;

			Node* tmp = data[cur];
			data[cur] = data[child];
			data[child] = tmp;
			cur = child;
		}
		return ret;
	}
};
struct MAXHEAP {
	int size = 0;
	Node* data[MAX_SIZE];

	void init() {
		size = 0;
	}
	void push(Node* value) {
		data[size] = value;
		int cur = size++;

		while (cur > 0 && data[cur]->n > data[(cur - 1) / 2]->n) {
			Node* tmp = data[cur];
			data[cur] = data[(cur - 1) / 2];
			data[(cur - 1) / 2] = tmp;
			cur = (cur - 1) / 2;
		}
	}
	Node* pop() {
		Node* ret = data[0];
		data[0] = data[--size];

		int cur = 0;
		int child;
		while (cur * 2 + 1 <= size) {
			if (cur * 2 + 1 == size)
				child = cur * 2 + 1;
			else
				child = (data[cur * 2 + 1]->n > data[cur * 2 + 2]->n) ? cur * 2 + 1 : cur * 2 + 2;

			if (data[cur]->n > data[child]->n)
				break;

			Node* tmp = data[cur];
			data[cur] = data[child];
			data[child] = tmp;
			cur = child;
		}
		return ret;
	}
};
MAXHEAP maxHeap;
MINHEAP minHeap;

Node* get_node(int num) {
	Node* ret = &pool[ptr++];
	ret->n = num;
	ret->isDelete = false;
	return ret;
}

void init() {
	maxHeap.init();
	minHeap.init();
	ptr = 0;
}

void operation(int cnt) {
	for (int i = 0; i < cnt; i++) {
		char c; int num;
		cin >> c >> num;
		if (c == 'I') {
			Node* newNode = get_node(num);
			maxHeap.push(newNode);
			minHeap.push(newNode);
		}
		else if (c == 'D') {
			if (num == 1) {
				Node* top = NULL;
				while (maxHeap.size) {
					top = maxHeap.pop();
					if (!top->isDelete)
						break;
				}
				if(top)
					top->isDelete = true;
			}
			else if (num == -1) {
				Node* top = NULL;
				while (minHeap.size) {
					top = minHeap.pop();
					if (!top->isDelete)
						break;
				}
				if (top)
					top->isDelete = true;
			}
		}
	}
	
	bool isEmpty = true;
	int min, max;
	while (minHeap.size) {
		Node* top = minHeap.pop();
		if (!top->isDelete) {
			isEmpty = false;
			min = top->n;
			break;
		}
	}
	if (isEmpty) {
		cout << "EMPTY\n";
		return;
	}
	else {
		while (maxHeap.size) {
			Node* top = maxHeap.pop();
			if (!top->isDelete) {
				max = top->n;
				break;
			}
		}
	}
	cout << max << ' ' << min << '\n';
}

int main() {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int k; cin >> k;

		init();
		operation(k);
	}
}