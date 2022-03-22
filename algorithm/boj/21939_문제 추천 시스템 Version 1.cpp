#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int realLevel[100001];
struct problem {
	int id, level;
};
struct hard {
	bool operator()(problem& a, problem& b) {
		if (a.level == b.level)
			return a.id < b.id;
		return a.level < b.level;
	}
};
struct easy {
	bool operator()(problem& a, problem& b) {
		if (a.level == b.level)
			return a.id > b.id;
		return a.level > b.level;
	}
};
priority_queue<problem, vector<problem>, hard> hardPQ;
priority_queue<problem, vector<problem>, easy> easyPQ;

int recommend(int type) {
	if (type == 1) {
		while (hardPQ.top().level != realLevel[hardPQ.top().id]) {
			hardPQ.pop();
		}
		return hardPQ.top().id;
	}
	else if (type == -1) {
		while (easyPQ.top().level != realLevel[easyPQ.top().id]) {
			easyPQ.pop();
		}
		return easyPQ.top().id;
	}
}

void solved(int id) {
	realLevel[id] = 0;
}

void add(int id, int level) {
	realLevel[id] = level;
	hardPQ.push({ id, level });
	easyPQ.push({ id, level });
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int id, level;
		cin >> id >> level;

		realLevel[id] = level;
		hardPQ.push({ id, level });
		easyPQ.push({ id, level });
	}
}

int main() {
	fastio;

	init();

	cin >> m;
	for (int i = 0; i < m; i++) {
		string cmd; cin >> cmd;

		if (cmd == "add") {
			int id, level;
			cin >> id >> level;
			add(id, level);
		}
		else if (cmd == "solved") {
			int id; cin >> id;
			solved(id);
		}
		else if (cmd == "recommend") {
			int type; cin >> type;
			cout << recommend(type) << '\n';
		}
	}
}
