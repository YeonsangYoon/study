/**********************************************************************
작성일 : 2022-2-08
문제 :
	n개의 행성들의 3차원 좌표가 주어진다. 
	모든 행성이 서로 연결되게 터널을 뚫는 최소 비용을 구하라.
	두 행성간 터널 건설 비용 = min(|xA-xB|, |yA-yB|, |zA-zB|)
풀이 :
	행성의 개수 N : 1 ~ 100,000
	행성간 모든 간선을 고려할 시 n(n+1)/2개의 연산이 필요하다.
		=> 각 축의 일차원만 고려했을 때 인접한 행성하고만 간선을 생성한다.
		=> 3 * (n - 1)개의 간선이 생성된다.
	생성된 간선을 heap에 넣고 mst를 수행한다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

// union-find 구현
struct disJointSet {
	vector<int> parent;

	disJointSet(int n) : parent(n + 1) {
		for (int i = 0; i <= n; i++)
			parent[i] = i;
	}
	int find(int n) {
		if (parent[n] == n) return n;
		return parent[n] = find(parent[n]);
	}
	void merge(int a, int b) {
		a = find(a);
		b = find(b);
		if (a == b) return;
		parent[a] = b;
	}
};
// 행성 idx와 1차원 좌표 구조체
struct coordinate {
	int idx, pos;
};
bool cmp(coordinate& a, coordinate& b) {
	return a.pos < b.pos;
}
vector<coordinate> xList;
vector<coordinate> yList;
vector<coordinate> zList;

// 간선과 간선 heap 구현
struct edge {
	int v1, v2, cost;
};
struct compare {
	bool operator()(edge& a, edge& b) {
		return a.cost > b.cost;
	}
};
priority_queue<edge, vector<edge>, compare> pq;

void init(int n) {
	// 각 변수 초기화
	for (int i = 1; i <= n; i++) {
		int x, y, z;
		cin >> x >> y >> z;

		xList.push_back({ i, x });
		yList.push_back({ i, y });
		zList.push_back({ i, z });
	}

	sort(xList.begin(), xList.end(), cmp);
	sort(yList.begin(), yList.end(), cmp);
	sort(zList.begin(), zList.end(), cmp);

	for (int i = 0; i < n - 1; i++) {
		pq.push({ xList[i].idx, xList[i + 1].idx, xList[i + 1].pos - xList[i].pos });
		pq.push({ yList[i].idx, yList[i + 1].idx, yList[i + 1].pos - yList[i].pos });
		pq.push({ zList[i].idx, zList[i + 1].idx, zList[i + 1].pos - zList[i].pos });
	}
}
int mst(int n) {
	// minimum spanning tree 구현
	int ret = 0;
	disJointSet djs(n);

	for (int i = 0; i < n - 1; i++) {
		edge now = pq.top(); pq.pop();

		if (djs.find(now.v1) == djs.find(now.v2)) {
			i--;
			continue;
		}

		djs.merge(now.v1, now.v2);
		ret += now.cost;
	}

	return ret;
}

int main() {
	fastio;

	int n; cin >> n;
	init(n);
	cout << mst(n);

	return 0;
}