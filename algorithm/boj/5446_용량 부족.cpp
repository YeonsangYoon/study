#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct TRIE {
	bool isData = false;
	map<char, TRIE*> child;
};

void insert(TRIE* root, string s) {
	for (char& c : s) {
		if (!root->child[c])
			root->child[c] = new TRIE();
		root = root->child[c];
	}
	root->isData = true;
}
TRIE* build_trie(int n) {
	TRIE* trie = new TRIE();

	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		insert(trie, s);
	}
	return trie;
}
void debug_trie(TRIE* root, string word) {
	map<char, TRIE*>::iterator iter;
	for (iter = root->child.begin(); iter != root->child.end(); iter++) {
		word.push_back(iter->first);
		debug_trie(iter->second, word);
		word.pop_back();
	}
	if (root->isData) {
		cout << word << '\n';
	}
	delete root;
}

int main() {
	fastio;

	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int n, m;
		cin >> n;
		TRIE* deleteTrie = build_trie(n);
		
		cin >> m;
		if (m == 0)
			cout << 1 << '\n';
		TRIE* remainTrie = build_trie(m);
	}
}