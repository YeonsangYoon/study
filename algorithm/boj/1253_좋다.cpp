#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int number[2001];
bool isGoodNumber[2001];

int get_idx(int num) {
	int l = 1, r = n, mid;
	while (l < r) {
		mid = (l + r) / 2;

		if (number[mid] >= num)
			r = mid;
		else
			l = mid + 1;
	}
	return r;
}

int get_gn_count() {
	int sum, idx;
	for (int i = 1; i <= n; i++) {
		for (int j = i + 1; j <= n; j++) {
			sum = number[i] + number[j];
			idx = get_idx(sum);
			
			for (int k = idx; k <= n; k++) {
				if (number[k] != sum) break;
				else if (k == i || k == j) continue;

				isGoodNumber[k] = true;
			}
		}
	}
	int cnt = 0;
	for (int i = 1; i <= n; i++)
		if (isGoodNumber[i])
			cnt++;
	return cnt;
}

void init() {
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> number[i];
	}
	sort(number + 1, number + n + 1);
}

int main(void) {
	fastio;
	init();

	cout << get_gn_count();
}