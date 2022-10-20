#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<int> arr;

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

int solve() {
	int ret = 0;
	for (int i = 0; i < n; i++) {
		for (int j = i + 1; j < n; j++) {
			ret = max(ret, gcd(arr[i], arr[j]));
		}
	}
	return ret;
}

vector<string> split(string s) {
	vector<string> ret;
	string tmp;
	for (char& c : s) {
		if (c == ' ') {
			ret.push_back(tmp);
			tmp.clear();
		}
		else {
			tmp.push_back(c);
		}
	}
	ret.push_back(tmp);
	return ret;
}

void init() {
	string s;
	getline(cin, s);
	vector<string> result = split(s);
	n = result.size();

	arr.clear();
	for (string& num : result) {
		arr.push_back(stoi(num));
	}
}

int main(void) {
	fastio;

	int tc; cin >> tc;
	cin.ignore();
	for (int i = 0; i < tc; i++) {
		init();
		cout << solve() << '\n';
	}
}