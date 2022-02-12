#include <iostream>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int main() {
	fastio;

	int n; cin >> n;
	cout << ((n == 1) ? 'B' : 'A');
}