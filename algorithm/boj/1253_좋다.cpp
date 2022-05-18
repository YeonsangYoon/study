#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int number[2001];

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}
	sort(number + 1, number + n);
}

int main(void) {
	fastio;
	init();

}