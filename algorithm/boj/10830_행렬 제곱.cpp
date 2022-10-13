#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 1000
typedef long long ll;
typedef vector<vector<int>> matrix;

int n, Pmax;
ll p;
matrix dp[40];

matrix mul(matrix a, matrix b) {
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

void fill_dp() {
	for (int i = 1; i <= Pmax; i++) {
		dp[i] = mul(dp[i - 1], dp[i - 1]);
	}
}

void init() {
	cin >> n >> p;
	for (int i = 40; i >= 0; i--) {
		if ((ll)1 << i < p) {
			Pmax = i + 1;
			break;
		}
	}

	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			int tmp; cin >> tmp;
			v.push_back(tmp);
		}
		dp[0].push_back(v);
	}
}

int main(void) {
	fastio;
	init();
	fill_dp();
	
	matrix cur;
	for (int i = 0; i < n; i++) {
		vector<int> v;
		for (int j = 0; j < n; j++) {
			if (i == j) v.push_back(1);
			else v.push_back(0);
		}
		cur.push_back(v);
	}

	for (int i = Pmax; i >= 0; i--) {
		if ((ll)1 << i <= p) {
			cur = mul(cur, dp[i]);
			p -= (ll)1 << i;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << cur[i][j] << ' ';
		}
		cout << '\n';
	}
}