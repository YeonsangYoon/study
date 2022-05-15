/**********************************************************************
작성일 : 2022-5-15
문제 :
	
풀이 :
	
시간 제한 : 2초
메모리 제한 : 128MB
예상 시간복잡도 : O(d * p)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, m;
string king;
vector<int> adjlist[1000];
map<string, int> id;
string name[1000];

void init() {
	cin >> n >> m;
	cin >> king;

	int ptr = 1;
	id[king] = ptr;
	name[ptr] = king;

	for (int i = 0; i < n; i++) {
		string c, f, m;
		cin >> c >> f >> m;
		if (!id[c]) {
			id[c] = ptr;
			name[ptr++] = c;
		}
		if (!id[c]) {
			id[c] = ptr;
			name[ptr++] = c;
		}
	}
}

int main(void) {
	fastio;
	init();
}