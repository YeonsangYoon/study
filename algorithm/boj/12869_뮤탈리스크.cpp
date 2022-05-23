#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int hp[3];
int damage[3] = { 9, 3, 1 };

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> hp[i];
}

int main(void) {
	fastio;
	init();
}