#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int arr[10001], brr[10001];
string a, b;

string solve() {
	string ret;

	int prev = 0;
	for (int i = 0; i < n; i++) {
		int sum = arr[i] + brr[i] + prev;
		ret.push_back(sum % 10 + '0');
		prev = sum / 10;
	}
	if(prev > 0)
		ret.push_back(prev + '0');
	reverse(ret.begin(), ret.end());
	return ret;
}

void init() {
	cin >> a >> b;
	int alen = (int)a.size();
	int blen = (int)b.size();
	n = max(alen, blen);

	for (int i = 0; i < alen; i++)
		arr[i] = a[alen - 1 - i] - '0';
	for (int i = 0; i < blen; i++)
		brr[i] = b[blen - 1 - i] - '0';
}

int main(void) {
	fastio;
	init();

	cout << solve();
}