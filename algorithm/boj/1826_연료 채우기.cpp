/**********************************************************************
작성일 : 2022-2-11
문제 :
	마을 까지 도착하기 위해 들려야한 주유소의 최소 개수
	1km가는데 1L의 연료가 소모된다. 
풀이 :
	처음에는 완전탐색과 가지치기를 활용하였는데 생각만큼 시간단축이 안됨.
	heap을 이용한 그리디를 이용하여 해결했다.
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <queue>
#include <vector>
#include <algorithm>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int remainFuel, dist;
struct info {
	int pos, fuel;
};
bool cmp(info& a, info& b) {
	return a.pos < b.pos;
}
vector<info> gasStation;

void input() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int pos, fuel;
		cin >> pos >> fuel;
		gasStation.push_back({ pos, fuel });
	}

	sort(gasStation.begin(), gasStation.end(), cmp);
	
	cin >> dist >> remainFuel;
}

int solve() {
	int i = 0;
	int cnt = 0;
	priority_queue<int> pq;

	while (remainFuel < dist) {
		while (i < n && gasStation[i].pos <= remainFuel) {
			pq.push(gasStation[i++].fuel);
		}

		if (pq.empty())
			return -1;

		remainFuel += pq.top(); pq.pop();
		cnt++;
	}

	return cnt;
}

int main() {
	fastio;

	input();
	cout << solve();
}