#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

#define MAX_TREE_SIZE 262144
typedef long long ll;

int n, S;
ll segTree[MAX_TREE_SIZE];

void init() {
	cin >> n;
	S = 1;
	while (S < n) S <<= 1;

	memset(segTree, 0, sizeof(segTree));
	for (int i = S; i < S + n; i++)
		cin >> segTree[i];
	for (int i = S - 1; i > 0; i--)
		segTree[i] = min(segTree[i * 2], segTree[i * 2 + 1]);
}

int main(void) {
	fastio;
	
	while (1) {
		init();
		if (n == 0) break;

		int maxVal = 0;
		for (int len = 1; len <= n; len++) {

		}
	}
}