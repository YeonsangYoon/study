/**********************************************************************
작성일 : 2022-2-20
문제 :
	n개의 플러그를 가진 멀티탭을 이용하여 k번 가전제품을 사용하고자 할때
	플러그를 뽑는 최소 횟수를 구하라.
풀이 :
	완전 탐색 사용시 n^(k-n)번 연산해야한다. 따라서 완전탐색은 불가능하다.
	그리디 or dp를 고려해야하는 데 그리디가 가능한 경우이다.
	1. 멀티탭이 비어있을 경우 : 비어있는 곳에 추가
	2. 멀티탭이 꽉차있는 경우
		- 이미 추가된 전자제품 : 넘어간다.
		- 아직 추가안된 전자제품 : 앞으로 사용하지 않을 것들 or 가장 나중에 사용할 것
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <vector>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, k;
bool isPluged[101];
vector<int> multitap;
vector<int> useOrder;

void init() {
	cin >> n >> k;
	for (int i = 0; i < k; i++) {
		int n; cin >> n;
		useOrder.push_back(n);
	}
}

int get_idx(int id, int idx) {
	for (int i = idx; i < (int)useOrder.size(); i++) {
		if (useOrder[i] == id)
			return i;
	}
	return -1;
}

int solve() {
	int cnt = 0;
	for (int i = 0; i < (int)useOrder.size(); i++) {
		int id = useOrder[i];

		if (isPluged[id]) {
			continue;
		}
		else if ((int)multitap.size() < n) {
			multitap.push_back(id);
			isPluged[id] = true;
			continue;
		}
		

		int idx;
		int ret = 0;
		for (int j = 0; j < (int)multitap.size(); j++) {
			int tmp = get_idx(multitap[j], i + 1);
			if (tmp == -1) {
				idx = j;
				break;
			}
			else if (ret < tmp) {
				idx = j;
				ret = tmp;
			}
		}
		isPluged[multitap[idx]] = false;
		isPluged[id] = true;
		multitap[idx] = id;
		cnt++;
	}
	return cnt;
}

int main() {
	fastio;

	init();
	cout << solve();
}