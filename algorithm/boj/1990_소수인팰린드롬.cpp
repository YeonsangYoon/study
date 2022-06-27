#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define Limit 10000000

int a, b;
int isPrime[Limit + 1];
int isPalindrome[Limit + 1];
deque<int> cur;

void set_prime() {
	memset(isPrime, true, sizeof(isPrime));
	isPrime[0] = isPrime[1] = false;

	for (int i = 2; i <= b; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j <= b; j += i)
				isPrime[j] = false;
		}
	}
}

void set_palindrome() {
	int num = 0;
	for (int& i : cur) {
		num *= 10;
		num += i;
	}
	if (num > b || (int)cur.size() >= 8) return;

	if (!cur.empty())
		if (cur[0] != 0)
			isPalindrome[num] = true;

	for (int i = 0; i < 10; i++) {
		cur.push_back(i);
		cur.push_front(i);
		set_palindrome();
		cur.pop_back();
		cur.pop_front();
	}
}

void init() {
	cin >> a >> b;
	b = min(Limit, b);
}

int main(void) {
	fastio;
	init();

	set_prime();
	set_palindrome();
	for (int i = 0; i < 10; i++) {
		cur.push_back(i);
		set_palindrome();
		cur.pop_back();
	}

	for (int i = a; i <= b; i++)
		if (isPrime[i] && isPalindrome[i])
			cout << i << '\n';
	cout << -1;
}