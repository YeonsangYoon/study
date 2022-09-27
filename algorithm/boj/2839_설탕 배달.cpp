#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int main(void) {
	fastio;
	int n;
	cin >> n;

	int cnt = 0;
	while (n > 0) {
		if (n % 5 == 0)
			break;
		n -= 3;
		cnt++;
	}

	if (n < 0)
		cout << -1;
	else
		cout << cnt + n / 5;
}