#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int get_longest_substr(deque<char>& s) {
	int m = s.size();
	int begin = 1, matched = 0;
	vector<int> table(m, 0);

	while (begin + matched < m) {
		if (s[matched] == s[begin + matched]) {
			matched++;
			table[begin + matched - 1] = matched;
		}
		else {
			if (matched == 0)
				begin++;
			else {
				begin += matched - table[matched - 1];
				matched = table[matched - 1];
			}
		}
	}
	int ret = 0;
	for (int& i : table)
		ret = max(ret, i);
	return ret;
}

int main(void) {
	fastio;
	
	string src; cin >> src;
	deque<char> dq;
	for (char& c : src) {
		dq.push_back(c);
	}

	int result = 0;
	while (!dq.empty()) {
		result = max(result, get_longest_substr(dq));
		dq.pop_front();
	}
	cout << result;
}