/**********************************************************************
작성일 : 2022-5-24
문제 :
	뮤탈리스크가 scv를 공격할 때 한번에 세개의 scv를 공격한다.
	9, 3, 1로 점차 적은 데미지로 공격한다. 이때, 모든 scv를 파괴하기 위한
	최소 공격횟수를 구하라.
풀이 :
	scv의 개수는 1 ~ 3이고, 체력은 1 ~ 60이다.
	체력이 많은 scv에게 높은 데미지를 주는 것이 답이 아니다.
	ex) 12 10 4의 경우 (9, 3, 1)의 데미지를 주는 것이 아니라 (9, 1, 3)의 데미지를 줘야한다.
	따라서 dp와 메모이제이션을 통해 구현하였다.
시간 제한 : 2초
메모리 제한 : 512MB
예상 시간복잡도 : O(m^4) (m : scv의 체력)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)
using namespace std;

int n;
int hp[3];
int dp[61][61][61][61];
vector<vector<int>> atOrder = {
	{{9, 3, 1}, {9, 1, 3}, {3, 9, 1}, {3, 1, 9}, {1, 9, 3}, {1, 3, 9}}
};

void attack_scv(int i, int j, int k, int cnt) {
	for (auto& order : atOrder) {
		int ni = max(0, i - order[0]);
		int nj = max(0, j - order[1]);
		int nk = max(0, k - order[2]);

		dp[ni][nj][nk][cnt] = 1;
	}
}

int get_attack_count() {
	for (int cnt = 0; cnt <= 60; cnt++) {
		if (dp[0][0][0][cnt]) return cnt;

		for (int i = 0; i <= hp[0]; i++) for (int j = 0; j <= hp[1]; j++) for (int k = 0; k <= hp[2]; k++) {
			if (dp[i][j][k][cnt]) {
				attack_scv(i, j, k, cnt + 1);
			}
		}
	};
}

void init() {
	cin >> n;
	for (int i = 0; i < n; i++)
		cin >> hp[i];
	dp[hp[0]][hp[1]][hp[2]][0] = 1;
}

int main(void) {
	fastio;
	init();
	cout << get_attack_count();
}