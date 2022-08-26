#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
string input;

bool is_valid() {
	stack<char> st;

	for (char& c : input) {
		if (st.empty() || c == '(') {
			st.push(c);
		}
		else {
			if (st.top() == '(')
				st.pop();
			else
				st.push(c);
		}
	}

	return st.empty();
}

void init() {
	cin >> input;
	n = (int)input.size();
}

int main(void) {
	fastio;
	init();

	int cnt = 0;
	for (int i = 0; i < n; i++) {
		char prev = input[i];
		if (prev == '(')
			input[i] = ')';
		else
			input[i] = '(';

		if (is_valid()) cnt++;
		input[i] = prev;
	}
	cout << cnt;
}