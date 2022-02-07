/**********************************************************************
작성일 : 2022-2-07
문제 :
	인접한 부분수열이 같지 않은 수열을 좋은 수열이라고 한다.
	원소가 1, 2, 3뿐이고 길이가 n인 좋은 수열 중 가장 작은 것을 출력하라
풀이 :
	가지치기를 활용한 dfs를 통해 시간을 줄이는 방법을 사용했다. 
	길이 절반 크기까지만 부분수열이 겹치기 때문에 수열 끝부분의 길이가 1~len/2인 부분수열만 검사한다.
	dfs를 수행하면서 계속 끝부분을 검사하면서 가지치기를 하면 시간이 많이 줄어든다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : 
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

bool stopflag = false;
string ans = "init";

void dfs(string arr, int n) {
	int len = (int)arr.size();
	for (int i = 1; i <= len / 2; i++) {
		if (arr.substr(len - i, i) == arr.substr(len - 2 * i, i))
			return;
	}

	if (len == n) {
		if (ans == "init") {
			ans = arr;
			stopflag = true;
		}
		return;
	}

	if(!stopflag)
		dfs(arr + '1', n);
	if(!stopflag)
		dfs(arr + '2', n);
	if(!stopflag)
		dfs(arr + '3', n);
}

int main() {
	fastio;

	int n;  cin >> n;
	dfs("", n);

	cout << ans << endl;
}