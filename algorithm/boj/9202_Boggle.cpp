/**********************************************************************
작성일 : 2022-2-01
문제 :
	단어 사전의 단어들이 주어지고, 각 TC마다 알파벳이 적혀있는 4x4크기 보드가 주어진다.
	이때 보드안에서 찾을 수 있는 단어의 개수, 점수, 가장 긴 단어를 찾아라
풀이 :
	trie를 사용하여 단어사전을 생성하고 dfs를 사용하여 맵을 탐색하면서 단어를 찾는다.

시간 제한 : 10초
메모리 제한 : 512MB
예상 시간복잡도 : ?
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct TRIE {
	int isData = false;
	TRIE* child[26];
};
int cnt = 0;
char board[4][4];
int visited[4][4];
int dy[8] = { 0, 0, 1, -1, 1, 1, -1, -1 };
int dx[8] = { 1, -1, 0, 0, 1, -1, 1, -1 };
map<string, int> findWords;

void insert(TRIE* cur, string s) {
	// trie에 words 삽입
	for (char& c : s) {
		int alpa = c - 'A';
		if (!cur->child[alpa]) {
			cur->child[alpa] = new TRIE();
		}
		cur = cur->child[alpa];
	}
	cur->isData = true;
}
void build_trie(TRIE* root) {
	// 주어진 단어들의 사전 build
	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		insert(root, s);
	}
}
void init() {
	// test case 변수 초기화
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			char c; cin >> c;
			board[i][j] = c;
		}
	}
	map<string, int>().swap(findWords);
	cnt = 0;
}
void dfs(TRIE* cur, int y, int x, string s) {
	// dfs를 통해 단어 찾기
	if (cur->isData) {
		cnt++;
		if (!findWords[s])
			findWords[s] = cnt;
	}
	for (int i = 0; i < 8; i++) {
		int ny = y + dy[i];
		int nx = x + dx[i];
		if (ny < 0 || ny >= 4 || nx < 0 || nx >= 4)
			continue;
		if (cur->child[board[ny][nx] - 'A'] && !visited[ny][nx]) {
			visited[ny][nx] = 1;
			s.push_back(board[ny][nx]);
			dfs(cur->child[board[ny][nx] - 'A'], ny, nx, s);
			s.pop_back();
			visited[ny][nx] = 0;
		}
	}
}
void find_words(TRIE *root) {
	// board에 있는 단어 전부 찾기
	for (int i = 0; i < 4; i++) {
		for (int j = 0; j < 4; j++) {
			int first = board[i][j] - 'A';
			if (root->child[first]) {
				string s; 
				s.push_back(board[i][j]);
				visited[i][j] = 1;
				dfs(root->child[first], i, j, s);
				memset(visited, 0, sizeof(visited));
			}
		}
	}
}
void get_score() {
	// 찾은 단어를 통해 점수, 가장 긴 단어, 단어 개수를 출력한다.
	int score = 0;
	int maxLen = 0;
	string longest;
	map<string, int>::iterator iter;
	for (iter = findWords.begin(); iter != findWords.end();iter++) {
		int len = iter->first.size();

		if (len > maxLen) {
			maxLen = len;
			longest = iter->first;
		}

		if (len == 3 || len == 4)
			score += 1;
		else if (len == 5)
			score += 2;
		else if (len == 6)
			score += 3;
		else if (len == 7)
			score += 5;
		else if (len == 8)
			score += 11;
	}
	
	cout << score << ' ' <<  longest << ' ' << (int)findWords.size() << '\n';
	return;
}

int main() {
	fastio;

	TRIE* trie = new TRIE();
	build_trie(trie);

	int t; cin >> t;
	for (int i = 1; i <= t; i++) {
		init();
		find_words(trie);
		get_score();
	}
}