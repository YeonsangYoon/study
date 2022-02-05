/**********************************************************************
작성일 : 2022-2-05
문제 :
	지워야할 파일들과 지우면 안되는 파일 이름이 주어졌을 때,
	rm 명령어를 사용하는 최소 횟수는? (명령어 끝에 * 사용가능)
풀이 :
	1. 지워야할 파일 목록과 지우면 안되는 파일 목록을 각각의 trie로 생성한다.
	2. 지워야할 파일 trie를 bfs로 순회하면서 순회할 때마다 지우면 안되는 파일 trie에 해당하는지 검사
	3. bfs를 통해 깊이 내려갈수록 count가 증가하는 구조이다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(N*L)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct TRIE {
	bool isData = false;
	string data;
	map<char, TRIE*> child;
};

void insert(TRIE* root, string s) {
	// 단어를 trie에 insert
	string tmp;
	for (char& c : s) {
		if (!root->child[c])
			root->child[c] = new TRIE();
		root = root->child[c];
		tmp += c;
		root->data = tmp;
	}
	root->isData = true;
}
TRIE* build_trie(int n) {
	// n개의 단어를 trie로 만든다.
	TRIE* trie = new TRIE();

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		insert(trie, s);
	}
	return trie;
}
void free_trie(TRIE *root) {
	// trie 메모리 해제
	map<char, TRIE*>::iterator iter;
	for (iter = root->child.begin(); iter != root->child.end(); iter++)
		if(iter->second)
			free_trie(iter->second);
	delete root;
}
bool find(TRIE* trie, string prefix) {
	// 접두어가 삭제하면 안되는 trie에 해당하는지 검사
	if (prefix.empty() && trie->child.empty())
		return false;

	bool ret = true;
	for (char& c : prefix) {
		if (trie->child[c]) {
			trie = trie->child[c];
		}	
		else {
			ret = false;
			break;
		}
	}
	return ret;
}
int count_rm_cmd(TRIE* dTrie, TRIE* rTrie) {
	// 사용해야할 rm 명령어의 개수 count
	// dTrie를 bfs로 순회하면서 접두어를 사용해도 되는지 검사
	int cnt = 0;
	queue<TRIE*> q;
	q.push(dTrie);

	while (!q.empty()) {
		TRIE* cur = q.front(); q.pop();
		
		if (find(rTrie, cur->data)) {
			if (cur->isData) {
				cnt++;
			}
			map<char, TRIE*>::iterator iter;
			for (iter = cur->child.begin(); iter != cur->child.end(); iter++) {
				q.push(iter->second);
			}
		}
		else {
			cnt++;
		}
	}
	return cnt;
}

int main() {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n;
		TRIE* deleteTrie = build_trie(n);	// 삭제해야할 trie 생성
		
		cin >> m;
		TRIE* remainTrie = build_trie(m);	// 삭제하면 안되는 trie 생성

		cout << count_rm_cmd(deleteTrie, remainTrie) << '\n';	// 개수 세기

		// 메모리 해제
		free_trie(deleteTrie);
		free_trie(remainTrie);
	}
}