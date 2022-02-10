/**********************************************************************
작성일 : 2022-2-10
문제 :
	n개의 별들이 주어졌을 때 모든 별들이 서로 연결될 수 있는 별자리를 만들고자 한다.
	별을 연결하는 비용은 x,y평면 상 별들의 거리만큼이다. 
	이때 별자리를 만드는 최소비용을 구하라.
풀이 :
	별 개수 n : 1 ~ 100
	모든 간선을 생성하는 데 오래걸리지 않음(n(n-1)/2)
	생성한 간선을 heap에 넣고 mst를 수행
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 :
TEST 결과 : 통과
**********************************************************************/
#include <iostream>
#include <vector>
#include <queue>
#include <math.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

struct disJointSet {
	vector<int> parent;

	void init(int n) {
		parent = {};
		for (int i = 0; i <= n; i++)
			parent.push_back(i);
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
struct pos {
	double x, y;
};
struct edge {
	int a, b;
	double dist;
};
struct cmp {
	bool operator()(edge& a, edge& b) {
		return a.dist > b.dist;
	}
};

int n;
priority_queue<edge, vector<edge>, cmp> pq;

void init() {
	cin >> n;
	vector<pos> stars;
	for (int i = 0; i < n; i++) {
		double x, y;
		cin >> x >> y;
		stars.push_back({ x, y });
	}

	for (int i = 0; i < (int)stars.size(); i++) {
		for (int j = i + 1; j < (int)stars.size(); j++) {
			double xdiff = stars[i].x - stars[j].x;
			double ydiff = stars[i].y - stars[j].y;
			double dist = sqrt(xdiff * xdiff + ydiff * ydiff);

			pq.push({ i, j, dist });
		}
	}
}

double mst() {
	double retval = 0;

	disJointSet djs;
	djs.init(n);

	for (int i = 0; i < n - 1; i++) {
		edge now = pq.top(); pq.pop();

		if (djs.find(now.a) == djs.find(now.b)) {
			i--;
			continue;
		}
		djs.merge(now.a, now.b);
		retval += now.dist;
	}

	return retval;
}

int main() {
	fastio;

	init();

	cout << fixed;
	cout.precision(2);
	cout << mst();

	return 0;
}