#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MOD 1000
typedef long long ll;

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
			ret[i][j] = (a[i][j] + b[i][j]) % 1000;
		return ret;
	}
	friend matrix operator * (matrix a, matrix b) {
		int n = a.M.size(); 
		matrix ret(n);
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				for (int k = 0; k < n; k++) {
					ret[i][j] += a[i][k] * b[k][j];
					ret[i][j] %= 1000;
				}
			}
		}
		return ret;
	}
};

int n, Pmax = 39;
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

matrix _pow(matrix& m, ll b) {
	matrix ret = E;
	while (b) {
		if (b & 1)
			ret *= m;
		m *= m;
		b >>= 1;
	}
	return ret;
}

void init() {
	cin >> n >> p;
	matrix a(n), e(n);
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> a[i][j];
			e[i][j] = (i == j) ? 1 : 0;
		}
	}
	A = a; E = e;
}

matrix solve(matrix m, ll b) {
	if (b == 1)
		return E;

	
}

int main(void) {
	fastio;
	init();

}