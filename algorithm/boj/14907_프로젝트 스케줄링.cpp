#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int rqTime[26], endTime[26], inDegree[26];
bool valid[26];
vector<int> adjlist[26];

vector<string> split(string s) {
	vector<string> ret;
	stringstream os(s);
	string tmp;

	while (getline(os, tmp, ' '))
		ret.push_back(tmp);
	return ret;
}

void init() {
	memset(valid, false, sizeof(valid));

	string line;
	while (getline(cin, line)) {
		vector<string> result = split(line);

		int s = result[0][0] - 'A';
		valid[s] = true;
		rqTime[s] = stoi(result[1]);

		if ((int)result.size() == 3) {
			for (char& c : result[2]) {
				adjlist[c - 'A'].push_back(s);
				inDegree[s]++;
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

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& nex : adjlist[now]) {
			if (--inDegree[nex] == 0) {
				q.push(nex);
				endTime[nex] = max(endTime[nex], rqTime[nex] + endTime[now]);
			}
		}
	}

	int ret = 0;
	for (int i = 0; i < 26; i++)
		ret = max(ret, endTime[i]);
	return ret;
}

int main(void) {
	fastio;
	init();

	cout << DAG();
}