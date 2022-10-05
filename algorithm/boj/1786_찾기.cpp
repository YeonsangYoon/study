#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

void init(string& a, string& b) {
	getline(cin, a);
	getline(cin, b);
}

vector<int> get_table(string& s) {
	int m = (int)s.size();
	vector<int> table(m, 0);

	for (int begin = 1; begin < m; begin++) {
		for (int i = 0; begin + i < m; i++) {
			if (s[begin + i] != s[i])
				break;
			table[begin + i] = max(table[begin + i], i + 1);
		}
	}
	return table;
}

vector<int> find_string(string& src, string& search) {
	vector<int> table = get_table(search);

}

int main(void) {
	fastio;

	string a, b;
	init(a, b);


}