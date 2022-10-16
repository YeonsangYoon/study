#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

typedef long long ll;
#define MOD 1000

struct matrix {
	vector<vector<int>> M;
	matrix(int n = 0) : M(n, vector<int>(n)) {}
	vector<int>& operator [] (int i) { return M[i]; }
	matrix& operator += (matrix m) { return *this = *this + m; }
	matrix& operator *= (matrix m) { return *this = *this * m; }
	friend matrix operator + (matrix a, matrix b) {
		int n = a.M.size(); 
		matrix ret(n);
		for (int i = 0; i < n; i++) for (int j = 0; j < n; j++) 
			ret[i][j] = (a[i][j] + b[i][j]) % MOD;
		return ret;
	}
	friend matrix operator * (matrix a, matrix b) {
		int n = a.M.size(); 
		matrix ret(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					ret[i][j] += a[i][k] * b[k][j];
					ret[i][j] %= MOD;
				}
			}
		}
		return ret;
	}
};

int n;
ll p;
matrix A, E;

void print_matrix(matrix& m) {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << m[i][j] << ' ';
		}
		cout << '\n';
	}
}

matrix _pow(matrix m, ll b) {
	matrix ret = E;
	while (b) {
		if (b % 2)
			ret *= m;
		m *= m;
		b >>= 1;
	}
	return ret;
}

matrix solve(matrix m, ll b) {
	if (b == 1)
		return m;
	else if (b % 2)
		return solve(m, b / 2 ) * (E + _pow(m, b / 2)) + _pow(m, b);
	else
		return solve(m, b / 2) * (E + _pow(m, b / 2));
}

void init() {
	cin >> n >> p;
	matrix a(n), e(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			a[i][j] %= MOD;
			e[i][j] = (i == j) ? 1 : 0;
		}
	}
	A = a; E = e;
}

int main(void) {
	fastio;
	init();

	matrix result = solve(A, p);
	print_matrix(result);
}