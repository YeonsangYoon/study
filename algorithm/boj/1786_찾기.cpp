#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void init(string& a, string& b) {
	getline(cin, a);
	getline(cin, b);
}

vector<int> get_table(string& str) {
	int m = (int)str.size();
	vector<int> table(m, 0);

	int s = 1, len = 0;
	while (s + len < m) {
		if (str[len] == str[s + len]) {
			len++;
			table[s + len - 1] = len;
		}
		else {
			if (len == 0)
				s++;
			else {
				s += len - table[len - 1];
				len = table[len - 1];
			}
		}
	}
	return table;
}

vector<int> find_string(string& src, string& search) {
	int n = (int)src.size(), m = (int)search.size();
	vector<int> ret;
	vector<int> table = get_table(search);
	int begin = 0, matched = 0;

	while (begin <= n - m) {
		if (matched < m && search[matched] == src[begin + matched]) {
			matched++;
			if (matched == m)
				ret.push_back(begin + 1);
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
	return ret;
}

int main(void) {
	fastio;

	string a, b;
	init(a, b);

	vector<int> result = find_string(a, b);
	cout << (int)result.size() << '\n';
	for (int& i : result)
		cout << i << ' ';
}