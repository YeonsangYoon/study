#include <bits/stdc++.h>
#define MAX 1000000000
using namespace std;

struct node {
    int a, c, t;
    bool operator<(const node& i) const {
        return t > i.t;
    }
};

vector<vector<int>> dp(151, vector<int>(151, MAX));

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alpGoal = 0, copGoal = 0;
    for (auto& a : problems) {
        alpGoal = max(alpGoal, a[0]);
        copGoal = max(copGoal, a[1]);
    }
    
    priority_queue<node> pq;
    pq.push({ alp, cop, 0 });
    dp[alp][cop] = 0;

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();
        if (now.a >= alpGoal && now.c >= copGoal)
            return now.t;

        for (auto& p : problems) {
            if (now.a >= p[0] && now.c >= p[1]) {
                pq.push({ now.a + p[2], now.c + p[3], now.t + p[4] });
            }
            else if (now.a < p[0] && now.c < p[1]) {
                pq.push({ p[0], p[1], now.t + p[0] - now.a + p[1] - now.c });
            }
            else if (now.a < p[0]) {
                pq.push({ p[0], now.c, now.t + p[0] - now.a });
            }
            else if (now.c < p[1]) {
                pq.push({ now.a, p[1], now.t + p[1] - now.c });
            }
        }
    }
}

/*
int main(void) {
    cout << solution(10, 10, { { 10, 15, 2, 1, 2 }, { 20, 20, 3, 3, 4 } }) << '\n';
    cout << solution(0, 0, { {0, 0, 2, 1, 2}, {4, 5, 3, 1, 2}, {4, 11, 4, 0, 2}, {10, 4, 0, 4, 2} });
}
*/
