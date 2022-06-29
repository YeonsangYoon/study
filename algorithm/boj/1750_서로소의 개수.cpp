#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int s[50];

int gcd(int a, int b) {
	int r;
	while (b > 0) {
		r = a % b;
		a = b;
		b = r;
	}
	return a;
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cout << s[i];
}

int main(void) {
	fastio;


}