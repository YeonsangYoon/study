/**********************************************************************
작성일 : 2022-2-02
문제 :
	여러개의 문자열과 각 문자가 적힌 격자모양 맵이 있다. 
	해당 맵을 이동하면서 주어진 문자열을 만들 수 있는 경로의 개수를 찾아라
풀이 :
	trie를 통해 단어 사전을 만들고, 
	dfs를 수행하면서 단어사전에 있는 경로를 찾는다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : ?
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n, m, k;
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
char hell[11][11];
vector<string> godStrings;

struct TRIE {
	bool isData = false;
	int cnt = 0;
	TRIE* child[26];
};

void insert(TRIE* root, string data) {	
	// trie에 문자열 추가
	for (char& c : data) {
		int num = c - 'a';
		if (!root->child[num])
			root->child[num] = new TRIE();
		root = root->child[num];
	}
	root->isData = true;
}
int find(TRIE* root, string data) {	
	// trie에서 단어를 찾고 cnt를 리턴
	for (char c : data) 
		root = root->child[c - 'a'];
	return root->cnt;
}
TRIE* build_trie() {
	// 문자열을 입력받고 trie를 생성
	TRIE* root = new TRIE();
	for (int i = 0; i < k; i++) {
		string s; cin >> s;
		godStrings.push_back(s);
		insert(root, s);
	}
	return root;
}
void dfs(TRIE* cur, int y, int x) {
	// dfs 수행하면서 단어에 맞는 경로 찾기
	if (cur->isData)
		cur->cnt++;

	for (int i = 0; i < 8; i++) {
		int ny = (y + dy[i]) % n;
		int nx = (x + dx[i]) % m;
		ny = ny ? ny : n;
		nx = nx ? nx : m;
		int num = hell[ny][nx] - 'a';

		if (cur->child[num]) {
			dfs(cur->child[num], ny, nx);
		}
	}
}
void count_case(TRIE* root) {
	// 경우의 수 count
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			int num = hell[i][j] - 'a';
			if (root->child[num])
				dfs(root->child[num], i, j);
		}
	}
}
void init() {
	// 입력
	cin >> n >> m >> k;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> hell[i][j];
		}
	}
}
int main() {
	fastio;

	init();
	TRIE* trie = build_trie();
	count_case(trie);

	for (string s : godStrings) {
		cout << find(trie, s) << '\n';
	}

	return 0;
}