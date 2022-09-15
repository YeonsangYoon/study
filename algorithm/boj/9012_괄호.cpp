#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

string s;

bool isValid() {
	stack<char> st;

	for (char& c : s) {
		if (st.empty() || c == '(')
			st.push(c);
		else if (st.top() == '(')
			st.pop();
		else
			st.push(c);
	}
	return st.empty();
}

void init() {
	s.clear();
	cin >> s;
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		init();

		if (isValid())
			cout << "YES\n";
		else
			cout << "NO\n";
	}
}