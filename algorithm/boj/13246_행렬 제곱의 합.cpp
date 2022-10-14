#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 1000
typedef long long ll;
typedef vector<vector<int>> matrix;

int n, Pmax = 39;
ll p;
matrix dp[40];

matrix mul(matrix& a, matrix& b) {
	matrix ret;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int k = 0; k < n; k++) {
				tmp += (a[i][k] * b[k][j]);
				tmp %= MOD;
			}
			v.push_back(tmp);
		}
		ret.push_back(v);
	}
	return ret;
}

void init() {
	cin >> n >> p;

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			v.push_back(tmp);
		}
		dp[0].push_back(v);
	}

	for (int i = 1; i <= Pmax; i++) {
		dp[i] = mul(dp[0], dp[0]);
	}
}

int main(void) {
	fastio;
	init();
}