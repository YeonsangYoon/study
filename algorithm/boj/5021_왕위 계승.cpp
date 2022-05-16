/**********************************************************************
작성일 : 2022-05-16
문제 :
	한 나라의 왕족에 대한 정보가 주어진다. 해당 정보는 자식, 2명의 부모의 이름으로 주어진다.
	현재 왕의 이름이 주어질 때 m개의 다음 왕 후보 중 혈통이 가장 높은 사람을 구하라.
풀이 :
	위상정렬을 통해 각 사람의 혈통을 계산한다.
	이렇게 계산한 혈통을 통해 m개의 후보 중 가장 혈통이 높은 사람을 구했다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
int inDegree[200];		// 진입차수
double priority[200];	// 혈통 수치
string king;			// 기존 왕
string name[200];		// id -> name
map<string, int> id;	// name -> id
vector<int> adjlist[200];	// 인접리스트

string get_next_king() {
	// m개의 후보 중 다음 왕 후보를 리턴
	string nextKing = "";
	double pr = 0.0;

	for (int i = 0; i < m; i++) {
		string candi;
		cin >> candi;

		if (priority[id[candi]] > pr) {
			nextKing = candi;
			pr = priority[id[candi]];
		}
	}
	return nextKing;
}

void set_priority() {
	// 혈통 수치를 계산(위상정렬)
	queue<int> q;
	for (int i = 1; i <= (int)id.size(); i++) {
		if (inDegree[i] == 0)
			q.push(i);
	}

	while (!q.empty()) {
		int now = q.front(); q.pop();

		for (int& next : adjlist[now]) {
			priority[next] += (priority[now] / 2);
			if (--inDegree[next] == 0)
				q.push(next);
		}
	}
}

void init() {
	// 변수 입력 및 초기화
	cin >> n >> m;
	cin >> king;
	
	int ptr = 1;
	for (int i = 0; i < n; i++) {
		string c, f, m;
		cin >> c >> f >> m;
		
		if (!id[c]) {
			id[c] = ptr;
			name[ptr++] = c;
		}
		if (!id[f]) {
			id[f] = ptr;
			name[ptr++] = f;
		}
		if (!id[m]) {
			id[m] = ptr;
			name[ptr++] = m;
		}

		adjlist[id[f]].push_back(id[c]);
		adjlist[id[m]].push_back(id[c]);
		inDegree[id[c]] += 2;
	}
	priority[id[king]] = 1.0;
}

int main(void) {
	fastio;
	init();
	set_priority();

	cout << get_next_king();
}