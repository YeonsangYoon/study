#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cout.tie(0), cin.tie(0)
using namespace std;


int chcnt[26];

int init() {
	string s;
	cin >> s;
	
	for (char& c : s)
		chcnt[c - 'A']++;

	int idx = 26, cnt = 0;
	for (int i = 0; i < 26; i++) {
		if (chcnt[i] % 2) {
			cnt++;
			idx = i;
		}
	}
	return (cnt > 1) ? -1 : idx;
}

int main(void) {
	fastio;
	int center = init();

	if (center == -1) {
		cout << "I'm Sorry Hansoo";
		return 0;
	}

	string s;
	for (int i = 0; i < 26; i++) {
		for (int j = 0; j < chcnt[i] / 2; j++)
			s.push_back('A' + i);
	}

	cout << s;
	if (center < 26) {
		char c = center + 'A';
		cout << c;
	}
	reverse(s.begin(), s.end());
	cout << s;
}