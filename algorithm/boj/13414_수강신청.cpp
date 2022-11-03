#include <bits/stdc++.h>
#include <unordered_map>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int k, l;
vector<string> q;
unordered_map<string, int> idMap;

void init() {
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		string id; cin >> id;
		q.push_back(id);
		idMap[id] = i;
	}
}

int main(void) {
	fastio;
	init();

	int cnt = 0;
	for (int i = 0; i < l; i++) {
		if (cnt == k) break;
		if (idMap[q[i]] == i) {
			cnt++;
			cout << q[i] << '\n';
		}
	}
}