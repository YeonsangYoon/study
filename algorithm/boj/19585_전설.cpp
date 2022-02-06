/**********************************************************************
작성일 : 2022-2-06
문제 :
	C개의 색상과 N개의 닉네임들이 주어졌을 때 
	Q개의 팀명 중 색상 + 닉네임의 규칙인 것을 확인하라
풀이 :
	색상과 닉네임들을 각각의 trie로 생성한다.(이때 닉네임은 역순으로 저장)
	각 팀명을 두개의 trie에서 find 수행한다음 멈춰지는 위치가 같을 시 규칙을 만족하고
	아닐시 규칙을 만족하지 않는다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct TRIE {
	bool isData;
	map<char, TRIE*> child;
};

void insert(TRIE* root, string word) {	
	// trie에 word 삽입
	for (char& c : word) {
		if (!root->child[c])
			root->child[c] = new TRIE();
		root = root->child[c];
	}
	root->isData = true;
}
TRIE* build_trie(int n, bool rvs = false) {
	// trie 생성(rvs = true인 경우 단어를 역순으로 저장)
	TRIE* trie = new TRIE();
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		if (rvs)
			reverse(s.begin(), s.end());
		insert(trie, s);
	}
	return trie;
}
bool find(TRIE* colors, TRIE* names, string word) {
	// 규칙 만족하는 지 확인
	int len = (int)word.size();
	map<int, int> hash;

	for (int i = 0; i < len; i++) {		// 색상 종료 위치 hash에 저장
		if (colors->isData)
			hash[i] = 1;
		if (!colors->child[word[i]])
			break;
		colors = colors->child[word[i]];
	}
	for (int i = len - 1; i >= 0; i--) {	// 이름 종료 위치가 hash에 있으면 규칙 만족
		if (names->isData && hash[i + 1])
			return true;
		if (!names->child[word[i]])
			break;
		names = names->child[word[i]];
	}

	return false;
}

int main() {
	fastio;

	int n, m;
	cin >> n >> m;

	TRIE* colors = build_trie(n);
	TRIE* names = build_trie(m, true);

	int k; cin >> k;
	for (int i = 0; i < k; i++) {
		string s; cin >> s;

		if (find(colors, names, s))
			cout << "Yes\n";
		else
			cout << "No\n";
	}
}