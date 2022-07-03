#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int first_contest(int rank) {
	if (rank == 1)
		return 5000000;
	else if (rank >= 2 && rank <= 3)
		return 3000000;
	else if (rank >= 4 && rank <= 6)
		return 2000000;
	else if (rank >= 7 && rank <= 10)
		return 500000;
	else if (rank >= 11 && rank <= 15)
		return 300000;
	else if (rank >= 16 && rank <= 21)
		return 100000;
	else
		return 0;
}
int second_contest(int rank) {
	if (rank == 1)
		return 5120000;
	else if (rank >= 2 && rank <= 3)
		return 2560000;
	else if (rank >= 4 && rank <= 7)
		return 1280000;
	else if (rank >= 8 && rank <= 15)
		return 640000;
	else if (rank >= 16 && rank <= 31)
		return 320000;
	else
		return 0;
}

int main(void) {
	fastio;
	
	int tc; cin >> tc;
	for (int i = 0; i < tc; i++) {
		int a, b;
		cin >> a >> b;
		
		cout << first_contest(a) + second_contest(b) << '\n';
	}
}