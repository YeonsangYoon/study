/**********************************************************************
작성일 : 2022-01-17
문제 :
	두 개의 문이 서로 보이도록 거울을 설치하고자 한다.
	이때 설치해야할 거울의 최소 개수를 구하라.
풀이 :
	'거울을 설치할 수 있는 공간'과 '문'을 하나의 노드라고 생각하고
	각 노드를 연결하는 간선들을 생성한다. 
		=> edge를 생성하는 과정은 2차원 배열을 순회하여 가로방향, 세로방향 간선을 각각 생성했다.
	연결리스트를 생성하고 bfs를 수행하는 것은 순조롭게 구현했다.
	
	이번 문제는 주어진 2차원 배열을 그래프로 다시 추상화하는 과정이 관건이었다. 
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(n^3)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
char house[51][51];
vector<int> doors;
vector<int> adjlist[3000];

void init() {
	// 입력
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> house[i][j];
			if (house[i][j] == '#')
				doors.push_back(i * n + j);
		}
	}
}
void make_edge() {
	// 연결리스트 생성
	for (int i = 0; i < n; i++) {
		vector<int> rowNode, colNode;
		for (int j = 0; j < n; j++) {
			// 가로
			if (house[i][j] == '#' || house[i][j] == '!') {
				for (int k = 0; k < (int)rowNode.size(); k++) {
					adjlist[rowNode[k]].push_back(i * n + j);
					adjlist[i * n + j].push_back(rowNode[k]);
				}
				rowNode.push_back(i * n + j);
			}
			else if (house[i][j] == '*') {
				vector<int>().swap(rowNode);
			}
			// 세로
			if (house[j][i] == '#' || house[j][i] == '!') {
				for (int k = 0; k < (int)colNode.size(); k++) {
					adjlist[colNode[k]].push_back(j * n + i);
					adjlist[j * n + i].push_back(colNode[k]);
				}
				colNode.push_back(j * n + i);
			}
			else if (house[j][i] == '*') {
				vector<int>().swap(colNode);
			}
		}
	}
}
int bfs() {
	int dist[3000];
	int start = doors[0];
	int end = doors[1];
	
	for (int i = 0; i < 3000; i++) {
		dist[i] = INT_MAX;
		if (i == start) dist[i] = 0;
	}

	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int cur = q.front(); q.pop();

		for (int& nex : adjlist[cur]) {
			if (dist[nex] > dist[cur] + 1) {
				dist[nex] = dist[cur] + 1;
				q.push(nex);
			}
		}
	}
	return dist[end] - 1;
}

int main() {
	fastio;

	init();
	make_edge();
	cout << bfs();
}