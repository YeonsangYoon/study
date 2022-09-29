#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int rqTime[26], endTime[26], inDegree[26];
bool valid[26];
vector<int> adjlist[26];

vector<string> split(string s) {
	vector<string> ret;
	string tmp;

	for (char& c : s) {
		if (c == ' ') {
			ret.push_back(tmp);
			tmp.clear();
		}
		else {
			tmp.push_back(c);
		}
	}
	ret.push_back(tmp);
	return ret;
}

void init() {
	memset(valid, false, sizeof(valid));

	string s;
	while (getline(cin, s)) {
		vector<string> line = split(s);
		
		int cur = line[0][0] - 'A';
		valid[cur] = true;
		rqTime[cur] = stoi(line[1]);

		if ((int)line.size() == 3) {
			for (char& c : line[2]) {
				adjlist[c - 'A'].push_back(cur);
				inDegree[cur]++;
			}
		}
	}
}

int DAG() {
	queue<int> q;
	for (int i = 0; i < 26; i++) {
		if (valid[i] && inDegree[i] == 0) {
			q.push(i);
			endTime[i] = rqTime[i];
		}
	}

	int ret = 0;
	while (!q.empty()) {
		int now = q.front(); q.pop();
		ret = max(ret, endTime[now]);

		for (int& nex : adjlist[now]) {
			endTime[nex] = max(endTime[nex], endTime[now] + rqTime[nex]);
			if (--inDegree[nex] == 0) {
				q.push(nex);
			}
		}
	}
	return ret;
}

int main(void) {
	fastio;
	init();

	cout << DAG();
}