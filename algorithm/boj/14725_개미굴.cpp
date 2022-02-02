/**********************************************************************
작성일 : 2022-2-02
문제 :
	개미굴을 탐색하여 얻을 정보를 가지고 개미굴의 시각화된 표현을 출력하라
	얻은 정보 : trie의 줄기를 각 줄에 표현하여 준다.
풀이 :
	trie를 통해 사전이 아닌 문자열 트리를 구현하는 것을 알게됨.
	문자열을 사전순으로 저장하고 싶을 때 사용
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(n*k*t)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct TRIE {
	bool isData = false;
	int depth;
	string data;
	TRIE* child[26];
};

void insert(TRIE* cur, string s, string data, int depth) {
	// trie에 문자열 입력
	for (char& c : s) {
		int num = c - 'A';
		if (!cur->child[num])
			cur->child[num] = new TRIE();
		cur = cur->child[num];
	}
	cur->isData = true;
	cur->depth = depth;
	cur->data = data;
}
TRIE* build_trie() {
	// 입력 받은 값을 통해 trie를 만든다.
	TRIE* root = new TRIE();

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s;
		int k; cin >> k;
		for (int j = 0; j < k; j++) {
			string tmp; cin >> tmp;
			s += tmp;
			insert(root, s, tmp, j);
		}
	}
	return root;
}
void visualize_trie(TRIE* trie) {
	// 전위 순회를 하면서 trie를 시각화하여 표현
	if (trie->isData) {
		for (int i = 0; i < trie->depth; i++) 
			cout << "--";
		cout << trie->data << '\n';
	}

	for (int i = 0; i < 26; i++) {
		if (trie->child[i]) {
			visualize_trie(trie->child[i]);
		}
	}
}

int main() {
	fastio;

	TRIE* trie = build_trie();
	visualize_trie(trie);

	return 0;
}