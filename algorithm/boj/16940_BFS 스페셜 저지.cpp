#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
vector<int> Input;
vector<vector<int>> adjlist;

void init() {
	cin >> n;
	
	adjlist = vector<vector<int>>(n + 1, vector<int>());
	Input = vector<int>(n);

	for (int i = 0; i < n - 1; i++) {
		int a, b;
		cin >> a >> b;
		adjlist[a].push_back(b);
		adjlist[b].push_back(a);
	}
	for (int i = 0; i < n; i++)
		cin >> Input[i];
}

int main(void) {
	fastio;
	init();

}