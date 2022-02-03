/**********************************************************************
작성일 : 2022-2-03
문제 :
	두 문자열 집합의 교집합 개수를 구하라.
풀이 :
	map<string, int>를 사용하여 빠르게 구한다.
	trie로 구현해봤는데 속도가 훨씬 느렸다.
		=> 단순히 문자열 전체를 비교하는 것이기 때문에 이진 트리를 사용하는 map이 유리함
		=> if 문자열 내부까지 비교하는 경우는 trie를 사용할 수 도 있음.
시간 제한 : 2초
메모리 제한 : 1536MB
예상 시간복잡도 : O(n + mlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m;
map<string, int> dictionary;

int main() {
	fastio;

	cin >> n >> m;
	
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		dictionary[s] = 1;
	}

	int cnt = 0;
	for (int i = 0; i < m; i++) {
		string s; cin >> s;
		if (dictionary[s])
			cnt++;
	}
	cout << cnt;
}