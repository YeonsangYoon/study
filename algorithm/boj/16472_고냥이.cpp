/**********************************************************************
작성일 : 2022-04-22
문제 :
	문자열 번역기가 하나 있다. 이 번역기는 n개의 알파벳만 인식 가능하다.
	번역기를 통해 문자열 하나을 인식하고자 한다.
	이때 최대로 인식할 수 있는 연속된 문자열의 최대 길이를 구하라.
풀이 :
	문자열의 길이가 최대 100000이기 때문에 적어도 O(nlogn)의 시간복잡도를 가져야한다.

	나는 투포인터 알고리즘을 활용하여 O(n)의 시간복잡도로 해결하였다.
	현재 선택된 영영을 l, r 인덱스로 관리하고 해당 영역에서 사용된 알파벳 종류의 개수는 curUsed,
	각 알파벳당 선택된 횟수는 selected 배열에 저장하였다.

	curUsed가 n보다 작거나 같도록 유지하면서 투포인터 알고리즘을 구현하였다.
시간 제한 : 1초
메모리 제한 : 512MB
예상 시간복잡도 : O(n) (n : 문자열 길이)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n, sLen;
int selected[26];
string s;

int get_string_len() {
	// 투포인터 알고리즘
	int l = 0, r = 0;
	int ret = 0;
	int curUsed = 1;
	selected[s[0] - 'a'] = 1;

	while (r < sLen - 1 && l <= r) {
		if (curUsed < n || selected[s[r + 1] - 'a']) {
			r++;
			ret = max(ret, r - l + 1);
			if (selected[s[r] - 'a'] == 0)
				curUsed++;
			selected[s[r] - 'a']++;
		}
		else {
			selected[s[l] - 'a']--;
			if (selected[s[l] - 'a'] == 0)
				curUsed--;
			l++;
		}
	}
	return ret;
}

void init() {
	cin >> n >> s;
	sLen = (int)s.size();
}

int main(void) {
	fastio;
	init();

	cout << get_string_len();
}