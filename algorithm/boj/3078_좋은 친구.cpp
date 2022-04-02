/**********************************************************************
작성일 : 2022-04-02
문제 :
	좋은 친구란 이름 길이가 같고 성적 차이가 k 이하인 것이라한다.
	n명의 학생의 이름이 성적순으로 주어질 때 좋은 친구 쌍의 개수를 구하라.
풀이 :
	처음에는 정렬 후 이분탐색을 통해 각 학생의 좋은 친구 개수를 구하였다.
	이는 O(nlogn)의 시간복잡도이기 때문에 통과하였다.

	하지만, 성적 순으로 학생이 주어지기 때문에 이름 길이별로 queue를 선언하고
	길이별 queue에 push하면 각 학생당 좋은 친구의 개수를 구할 수 있다.
	이때 queue에서 성적 차이가 k보다 크면 계속 pop해줘야 한다.
	이 방법이 더 간단하게 구현가능하고, 시간복잡도 측면에서도 효율적이다.
시간 제한 : 1초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;
typedef long long ll;

int n, k;
queue<int> q[21];

ll solve() {
	ll cnt = 0;
	for (int i = 1; i <= n; i++) {
		string s; cin >> s;
		int len = (int)s.size();

		while (!q[len].empty()) {
			if (i - q[len].front() > k)
				q[len].pop();
			else
				break;
		}

		cnt += (ll)q[len].size();
		q[len].push(i);
	}
	return cnt;
}

int main(void) {
	fastio;

	cin >> n >> k;
	cout << solve();
}