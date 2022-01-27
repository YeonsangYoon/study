/**********************************************************************
작성일 : 2022-1-27
문제 :
	일직선 상에 놓인 n개의 탑이 있을 때, 이 탑들의 높이가 순서대로 주어진다.
	각 탑은 왼쪽으로 레이저를 발사했을 때 몇번째 탑에서 수신하는 지 구하라
풀이 :
	탑의 최대 개수 : 500000 => n^2으로는 못푼다.
	때문에 이를 고민하다 무슨 알고리즘을 써야하는 지 봤다.
	=> 스택
	어떻게 스택을 이용할 지 고민하다 정답을 찾았다. 
	스택을 어떻게 알고리즘 문제에서 이용하는지에 대해 깨달은 좋은 문제였다.
시간 제한 : 1.5초
메모리 제한 : 128MB
예상 시간복잡도 : O(n)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

int n;
int ans[500001];		// 정답 배열
struct Top {
	int idx, height;
};
vector<Top> Tops;

void input() {
	// 입력
	cin >> n;
	for (int i = 1; i <= n; i++) {
		int tmp; cin >> tmp;
		Tops.push_back({ i, tmp });
	}
}
void solve() {
	stack<Top> st;
	
	// 스택에 넣어가면서 기록
	for (int i = n - 1; i >= 0; i--) {
		Top newTop = Tops[i];

		if (st.empty()) {
			st.push(newTop);
		}
		else {
			while (!st.empty()) {
				if (newTop.height >= st.top().height) {
					ans[st.top().idx] = newTop.idx;
					st.pop();
				}
				else {
					break;
				}
			}
			st.push(newTop);
		}
	}
	// 아직 남아있는 것들은 수신 못하는 것들
	while (!st.empty()) {
		ans[st.top().idx] = 0;
		st.pop();
	}
}

int main() {
	fastio;

	input();
	solve();

	for (int i = 1; i <= n; i++)
		cout << ans[i] << ' ';
}