#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, totalCnt;
vector<vector<int>> server;



void init() {
	cin >> n;
	server = vector<vector<int>>(n, vector<int>(n));

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> server[i][j];
			totalCnt += server[i][j];
		}
	}
}

int main(void) {
	fastio;

}