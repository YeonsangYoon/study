#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int d, p;
struct pipe {
	int l, c;
};
vector<pipe> pipes;

bool cmp(pipe& a, pipe& b) {
	if (a.l == b.l)
		return a.c < b.c;
	return a.l < b.l;
}
void init() {
	cin >> d >> p;
	for (int i = 0; i < p; i++) {
		int l, c;
		cin >> l >> c;
		pipes.push_back({ l, c });
	}
	sort(pipes.begin(), pipes.end(), cmp);
}

int main() {
	fastio;
	
	init();

	return 0;
}