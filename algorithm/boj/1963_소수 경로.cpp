#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int visited[10000];
bool isPrime[10000];
vector<int> adjlist[10000];

void get_string(int num, int arr[]) {
	for (int i = 3; i >= 0; i--) {
		arr[i] = (num % 10);
		num /= 10;
	}
}
int get_number(int arr[]) {
	int ret = 0;
	for (int i = 0; i < 4; i++) {
		ret = ret * 10 + arr[i];
	}
	return ret;
}

void init() {
	memset(isPrime, true, sizeof(isPrime));
	for (int i = 2; i < 10000; i++) {
		if (isPrime[i]) {
			for (int j = i * 2; j < 10000; j += i) {
				isPrime[j] = false;
			}
		}
	}

	for (int i = 1000; i < 10000; i++) {
		if (!isPrime[i]) continue;

		int arr[4];
		get_string(i, arr);
		
		for (int j = 0; j < 4; j++) {
			for (int k = 0; k < 10; k++) {
				if ((j == 0 && k == 0) || arr[j] == k)
					continue;

				int tmp = arr[j];
				arr[j] = k;
				int num = get_number(arr);
				if(isPrime[num])
					adjlist[i].push_back(num);
				arr[j] = tmp;
			}
		}
	}
}

int bfs(int s, int e) {
	if (s == e) return 0;

	memset(visited, 0, sizeof(visited));
	queue<int> q;
	q.push(s);

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			if (visited[next] > 0) continue;

			visited[next] = visited[now] + 1;
			q.push(next);
		}
	}
	
	return visited[e] ? visited[e] : -1;
}

int main() {
	fastio;

	init();

	int t; cin >> t;
	for (int i = 0; i < t; i++) {
		int s, e;
		cin >> s >> e;
		
		int result = bfs(s, e);
		if (result >= 0)
			cout << result << '\n';
		else
			cout << "Impossible\n";
	}
}