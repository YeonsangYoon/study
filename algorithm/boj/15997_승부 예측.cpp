/**********************************************************************
작성일 : 2022-01-10
문제 :
	4개의 팀이 조별리그를 진행하고, 상위 2개의 팀이 본선에 진출한다고 했을 때
	총 6번의 매치업의 확률을 통해 각 팀이 본선에 진출할 확률을 구하라.
풀이 :
	조금 복잡한 구현문제
	구현 과정을 2단계로 나누면 다음과 같다.

	1. 6번의 매치를 통해 나올 수 있는 모든 경우의 수에 대한 확률을 구한다.
		- 총 6번의 매치의 경우의 수는 3^6이다.
		- 각 경우에 대한 확률은 dfs를 통한 완전탐색으로 구할 수 있다.
		- 각 매치의 확률을 곱해가면서 확률을 구한다.
	2. 6번의 매치를 완료한뒤 4개의 팀이 상위 2팀이 될 수 있는 확률을 구하고 자신의 확률에 더한다.
		- 만약 승점이 같으면 추첨을 통해 정하므로 확률을 팀 숫자로 나눈다.
시간 제한 : 1초
메모리 제한 : 256MB
예상 시간복잡도 : O(3^6) => O(1)
TEST 결과 : 통과
**********************************************************************/
#include <bits/stdc++.h>
#define fastio ios::sync_with_stdio(0), cin.tie(0), cout.tie(0)

using namespace std;

string teams[4];
double totalProb[4];
map<string, int> teamNumber;

struct matchResult {
	int winner;
	int loser;
	double probs[3];
};
matchResult records[6];

void init() {
	for (int i = 0; i < 4; i++) {
		string team;
		cin >> team;
		teams[i] = team;
		teamNumber[team] = i;
	}

	for (int i = 0; i < 6; i++) {
		string a, b;
		double w, d, l;
		cin >> a >> b;
		cin >> w >> d >> l;

		records[i] = { teamNumber[a], teamNumber[b], w, d, l };
	}
}
void dfs(int match, double curProb, vector<int> score) {
	if (match == 6) {
		pair<int, int> top = { 0, 0 };
		pair<int, int> second = { 0, 0 };

		for (int i = 0; i < 4; i++) {
			top.first = max(top.first, score[i]);
		}
		for (int i = 0; i < 4; i++) {
			if (score[i] != top.first) {
				second.first = max(second.first, score[i]);
			}
		}
		for (int i = 0; i < 4; i++) {
			if (score[i] == top.first)
				top.second++;
			if (score[i] == second.first)
				second.second++;
		}
		if (top.second > 0) {
			for (int i = 0; i < 4; i++) {
				if (top.first == score[i]) {
					if (top.second > 2) {
						totalProb[i] += (2 * curProb / top.second);
					}
					else {
						totalProb[i] += curProb;
					}
				}
			}
		}
		if (second.second > 0 && top.second < 2) {
			for (int i = 0; i < 4; i++) {
				if (second.first == score[i]) {
					totalProb[i] += (curProb / second.second);
				}
			}
		}

		return;
	}

	// win
	if (records[match].probs[0] > 0.0) {
		score[records[match].winner] += 3;
		dfs(match + 1, curProb * records[match].probs[0], score);
		score[records[match].winner] -= 3;
	}
	// draw
	if (records[match].probs[1] > 0.0) {
		score[records[match].winner] += 1;
		score[records[match].loser] += 1;
		dfs(match + 1, curProb * records[match].probs[1], score);
		score[records[match].winner] -= 1;
		score[records[match].loser] -= 1;
	}
	//lose
	if (records[match].probs[2] > 0.0) {
		score[records[match].loser] += 3;
		dfs(match + 1, curProb * records[match].probs[2], score);
		score[records[match].loser] -= 3;
	}
}

int main(void) {
	fastio;

	init();

	vector<int> s(4, 0);
	dfs(0, 1.0, s);

	cout << fixed;
	cout.precision(10);
	for (int i = 0; i < 4; i++) {
		cout << totalProb[i] << "\n";
	}

	return 0;
}