/**********************************************************************
작성일 : 2022-2-22
문제 :
	파일을 확장자별로 정리하여 각 확장자를 가진 파일이 몇개인지 사전순으로 출력하라
풀이 :
	split과 map을 활용하여 구현
시간 제한 : 3초
메모리 제한 : 1024MB
예상 시간복잡도 : O(nlogn)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

map<string, int> Hash;

string split(string s, char delim) {
	vector<string> retval;  // 리턴 값
	stringstream os(s);     // stream에 문자열 저장
	string tmp;

	while (getline(os, tmp, delim)) {   // getline으로 delim 만나기 전까지 tmp에 저장
		retval.push_back(tmp);
	}

	return retval.back();
}

int main() {
	fastio;

	int n; cin >> n;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		string ex = split(s, '.');
		
		if (Hash[ex])
			Hash[ex]++;
		else
			Hash[ex] = 1;
	}

	map<string, int>::iterator iter;
	for (iter = Hash.begin(); iter != Hash.end(); iter++) {
		cout << iter->first << ' ' << iter->second << '\n';
	}
}