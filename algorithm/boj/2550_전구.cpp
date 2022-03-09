/**********************************************************************
작성일 : 2022-3-09
문제 :
	전구와 스위치를 연결하는 선이 겹치면 두 전구 모두 안켜진다.
	이때 최대한 많은 전구를 켜기 위해 눌러야하는 스위치를 오름차순으로 출력하라
풀이 :
	전형적인 LIS 문제. (전깃줄 문제랑 비슷)
	하지만 입력이 스위치와 전구 자체가 주어지기 때문에 이를 indexarr로 바꿔야한다.
	
	스위치 : 2 4 1 5 3 
						=> 4 0 2 1 3
	전  구 : 4 5 1 3 2
	이렇게 연결된 index배열을 만들고 LIS를 수행한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define MAX 10001
using namespace std;

int n;
int swt[MAX], bulb[MAX];		// 스위치, 전구 배열
int bulbIdx[MAX], arr[MAX];
int Index[MAX];
vector<int> indexList;

int get_idx(int target) {
	int l = 0;
	int r = (int)indexList.size() - 1;

	while (l < r) {
		int mid = (l + r) / 2;

		if (indexList[mid] < target) {
			l = mid + 1;
		}
		else {
			r = mid;
		}
	}
	return (indexList[r] < target) ? r + 1 : r;
}

vector<int> LIS() {
	for (int i = 0; i < n; i++) {
		if (i == 0 || indexList.back() < arr[i]) {
			indexList.push_back(arr[i]);
			Index[i] = (int)indexList.size() - 1;
		}
		else {
			int idx = get_idx(arr[i]);
			indexList[idx] = arr[i];
			Index[i] = idx;
		}
	}
	
	vector<int> swtList;
	int idx = (int)indexList.size() - 1;

	for (int i = n - 1; i >= 0; i--) {
		if (Index[i] == idx) {
			swtList.push_back(swt[i]);
			idx--;
		}
	}
	sort(swtList.begin(), swtList.end());
	return swtList;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> swt[i];
		bulbIdx[swt[i]] = i;
	}
	for (int i = 0; i < n; i++) {
		cin >> bulb[i];
		arr[bulbIdx[bulb[i]]] = i;
	}
}

int main() {
	fastio;

	init();
	vector<int> result = LIS();

	cout << (int)result.size() << '\n';
	for (int& i : result)
		cout << i << ' ';
}