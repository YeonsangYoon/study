/**********************************************************************
작성일 : 2022-6-01
문제 :
	N개의 원소를 가지는 수열에서 M개를 뽑아 나열한 수열 구하라.
풀이 :
	재귀호출을 사용하여 순열 구현
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(nPm)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int arr[9];
bool visited[9];
vector<int> selected;

void permutation(int cnt) {
	if (cnt == m) {
		for (int& i : selected)
			cout << i << ' ';
		cout << '\n';
		return;
	}

	for (int i = 0; i < n; i++) {
		if (!visited[i]) {
			visited[i] = true;
			selected.push_back(arr[i]);
			permutation(cnt + 1);
			selected.pop_back();
			visited[i] = false;
		}
	}
}

void init() {
	cin >> n >> m;
	for (int i = 0; i < n; i++)
		cin >> arr[i];
	sort(arr, arr + n);
}

int main(void) {
	fastio;
	init();
	permutation(0);
}