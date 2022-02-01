/**********************************************************************
작성일 : 2022-2-01
문제 :
	전화번호 목록이 주어질 때 한 번호가 다른 번호의 접두어인 경우가 있는 지 판단
풀이 :
	trie를 이용하여 전화번호 목록을 구현한 뒤 접두어가 있는 지 판단
		=> 접두어가 있는 경우 : leaf가 아닌 노드에 data가 있는 경우
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n*L) (L : 문자열 길이)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

vector<string> phoneNumbers;

struct TRIE {
	bool isData = false;
	TRIE* child[10];
};

void insert(TRIE* cur, string s) {	// trie에 문자열 삽입
	for (char& c : s) {
		int num = c - '0';
		if (!cur->child[num]) {
			cur->child[num] = new TRIE();
		}
		cur = cur->child[num];
	}
	cur->isData = true;
}
void freeTrie(TRIE* cur) {			// trie 메모리 해제
	for (int i = 0; i < 10; i++) {
		if (cur->child[i])
			freeTrie(cur->child[i]);
	}
	free(cur);
}
bool isAns(TRIE* cur) {				// 정답 확인
	bool ret = true;
	for (int i = 0; i < 10; i++) {
		if (cur->child[i] && cur->isData) {
			return false;
		}
		else if (cur->child[i]) {
			ret &= isAns(cur->child[i]);
		}
	}
	return ret;
}

int main() {
	fastio;

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		TRIE* trie = new TRIE();

		int n; cin >> n;
		for (int j = 0; j < n; j++) {
			string s; cin >> s;
			insert(trie, s);
		}

		if (isAns(trie)) 
			cout << "YES" << '\n';
		else
			cout << "NO" << '\n';

		freeTrie(trie);
	}
	
}