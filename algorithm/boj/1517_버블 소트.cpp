/**********************************************************************
작성일 : 2022-2-23
문제 :
	버블 소트 수행시 swap하는 횟수를 구하라
풀이 :
	merge sort를 사용하여 counting 할 수 있다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
#define ARR_MAX_SIZE 500001
using namespace std;
typedef long long ll;

int n;
ll cnt = 0;
int arr[ARR_MAX_SIZE];
int sorted[ARR_MAX_SIZE];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++)
		cin >> arr[i];
}

void merge(int l, int m, int r) {
	int i = l;
	int j = m + 1;
	int k = l;

	while (i <= m && j <= r) {
		if (arr[i] <= arr[j]) {
			sorted[k++] = arr[i++];
		}
		else {
			cnt = cnt + m - i + 1;
			sorted[k++] = arr[j++];
		}
	}

	while (i <= m) {
		sorted[k++] = arr[i++];
	}
	while (j <= r) {
		sorted[k++] = arr[j++];
	}

	for (i = l; i <= r; i++)
		arr[i] = sorted[i];
}

void mergeSort(int l, int r) {
	if (l >= r) return;

	int mid = (l + r) / 2;
	mergeSort(l, mid);
	mergeSort(mid + 1, r);
	merge(l, mid, r);
}

int main() {
	fastio;

	init();
	mergeSort(1, n);
	cout << cnt;
}