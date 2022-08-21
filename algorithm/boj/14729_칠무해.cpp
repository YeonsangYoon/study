#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
priority_queue<double, vector<double>, greater<double>> score;

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		double tmp;
		cin >> tmp;
		score.push(tmp);
	}
}

int main(void) {
	fastio;
	init();

	cout << fixed;
	cout.precision(3);

	for (int i = 0; i < 7; i++) {
		cout << score.top() << '\n';
		score.pop();
	}
}