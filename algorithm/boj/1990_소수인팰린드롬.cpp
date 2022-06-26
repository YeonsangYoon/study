#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_INT 100000000

int a, b;
bool isPrime[MAX_INT + 1];

vector<int> get_prime() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	vector<int> ret;

	for (int i = 2; i <= b; i++) {
		if (isPrime[i]) {
			ret.push_back(i);
			for (int j = i * 2; j <= b; j += i)
				isPrime[j] = false;
		}
	}
	return ret;
}

bool isPalindrome(int num) {
	vector<int> v;
	while (num > 0) {
		v.push_back(num % 10);
		num /= 10;
	}

	int len = (int)v.size();

	for (int i = 0; i < (len / 2) + 1; i++) {
		if (v[i] != v[len - i - 1])
			return false;
	}
	return true;
}

int main(void) {
	fastio;
	cin >> a >> b;
	
	vector<int> primes = get_prime();

	for (int &i : primes) {
		if (isPrime[i])
			if (isPalindrome(i))
				cout << i << '\n';
	}
	cout << -1;

	return 0;
}