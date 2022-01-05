/**********************************************************************
작성일 : 2022-01-05
작성자 : 윤연상
문제 :
	숫자 하나가 계속 추가되는 집합의 중간 값을 구하는 문제(쿼리형)
풀이 :
	총 쿼리수는 최대 100,000개이다. 
	따라서 각 쿼리마다 숫자를 insert, find하는데 걸리는 시간은 logn이여야 한다.

	1. 처음에는 항상 중간값을 root로 유지하는 트리를 생각했지만, 
	트리의 특성인 재귀를 이용한 방법이 마땅히 떠오르지 않았다.

	2. 그 다음으로 minHeap과 maxHeap을 이용하여 중간값을 항상 유지하는 방법을 생각했다.
	
		중간값보다 작은 집합(maxHeap) <= 중간값 <= 중간값보다 큰 집합(minHeap)
	
		이렇게 자료구조를 구성한 뒤 쿼리마다 총 4개의 수를 비교하도록 구현하였다.
		(1) 중간값보다 작은 집합에서 제일 큰수
		(2) 중간값
		(3) 중간값보다 큰 집합에서 제일 작은 수
		(4) 새로 추가한 수
		또한, 짝수 개일 때 중간값은 2개 중 작은 수이므로 항상 중간값보다 큰 집합이 더 크도록 유지했다.
시간 제한 : 0.1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int center;
priority_queue<int, vector<int>, greater<int>> rightPart;	// 중간값보다 큰 집합(minHeap)
priority_queue<int, vector<int>, less<int>> leftPart;		// 중간값보다 작은 집합(maxHeap)

void print_center() { cout << center << "\n"; }	// 중간값 출력
void insert(int num) {		
	// 새로운 수 추가하는 함수
	if (leftPart.size() == rightPart.size()) {
		if (rightPart.empty()) {
			rightPart.push(max(center, num));
			center = min(center, num);
		}
		else if (num < leftPart.top()) {
			rightPart.push(center);
			center = leftPart.top();
			leftPart.pop();
			leftPart.push(num);
		}
		else if (num <= center) {
			rightPart.push(center);
			center = num;
		}
		else {
			rightPart.push(num);
		}
	}
	else if (leftPart.size() < rightPart.size()) {
		if (num <= center) {
			leftPart.push(num);
		}
		else if (num < rightPart.top()) {
			leftPart.push(center);
			center = num;
		}
		else {
			leftPart.push(center);
			center = rightPart.top();
			rightPart.pop();
			rightPart.push(num);
		}
	}
}

int main() {
	fastio;

	int n; cin >> n;
	
	cin >> center;	// 첫번째 숫자는 바로 center
	print_center();	

	for (int i = 0; i < n - 1; i++) {
		int num; cin >> num;	// 1. 숫자 입력
		insert(num);			// 2. 자료구조에 insert
		print_center();			// 3. 중간값 출력
	}
}