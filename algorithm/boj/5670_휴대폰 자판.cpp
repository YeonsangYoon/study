/**********************************************************************
작성일 : 2022-2-03
문제 :
	자동완성 기능 구현 문제. 
	n개의 단어가 주어졌을 때 각 단어를 입력하는 횟수의 평균을 구하라
	세부 규칙
		- 첫글자는 반드시 직접 입력
		- 다음에 입력할 글자가 한개뿐일때 직접 입력하지 않고 자동 완성한다.
풀이 :
	trie를 통해 단어 사전을 만들고, tree를 순회하면서 직접 word당 cnt를 구한다.
	child의 개수가 1개이면 cnt를 증가하지 않는 원리를 이용
	isData = true인 노드에서도 childCnt를 증가시켜야함 => 글자를 입력 안해도 단어가 되기 때문에
시간 제한 : 1초
메모리 제한 : 192MB
예상 시간복잡도 : O(tc * n * L) (tc : 테케 개수, n : 단어 개수, L : 단어 길이)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;
typedef vector<string> vstring;

struct TRIE {
	bool isData = false;
	int childCnt = 0;
	TRIE* child[26];
};
void insert(TRIE* root, string word) {
	for (char& c : word) {
		int num = c - 'a';
		if (!root->child[num]) {
			root->child[num] = new TRIE();
			root->childCnt++;
		}
		root = root->child[num];
	}
	root->isData = true;
	root->childCnt++;
}
TRIE* build_trie(vstring words) {
	TRIE* root = new TRIE();
	for (string& word : words) 
		insert(root, word);
	return root;
}
void free_trie(TRIE* trie) {
	for (int i = 0; i < 26; i++)
		if(trie->child[i])
			free_trie(trie->child[i]);
	delete trie;
}
double get_avg_count(TRIE* trie, vstring words, int n) {
	int ret = 0;
	for (string& word : words) {
		int cnt = 0;
		
		TRIE* cur = trie;
		for (char& c : word) {
			if (cur->childCnt != 1)
				cnt++;
			cur = cur->child[c - 'a'];
		}
		if (trie->childCnt == 1)
			cnt++;
		ret += cnt;
	}
	return (double)ret / n;
}
vstring input(int n) {
	vstring ret;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		ret.push_back(s);
	}
	return ret;
}
int main() {
	fastio;

	cout << fixed;
	cout.precision(2);

	int n;
	while (cin >> n) {
		vstring words = input(n);
		TRIE* trie = build_trie(words);
		cout << get_avg_count(trie, words, n) << '\n';
		free_trie(trie);
	}
}