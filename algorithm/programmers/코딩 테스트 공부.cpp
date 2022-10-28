#include <bits/stdc++.h>
using namespace std;

struct node {
    int a, c, t;
    bool operator<(const node& i) const {
        return t > i.t;
    }
};

bool visited[2000][2000];

int solution(int alp, int cop, vector<vector<int>> problems) {
    int alpGoal = 0, copGoal = 0;
    for (auto& p : problems) {
        alpGoal = max(alpGoal, p[0]);
        copGoal = max(copGoal, p[1]);
    }

    priority_queue<node> pq;
    pq.push({ alp, cop, 0 });

    while (!pq.empty()) {
        node now = pq.top(); pq.pop();
        if (now.a >= alpGoal && now.c >= copGoal)
            return now.t;
        else if (visited[now.a][now.c])
            continue;

        visited[now.a][now.c] = true;
        for (auto& p : problems) {
            if (now.a >= p[0] && now.c >= p[1]) {
                pq.push({ now.a + p[2], now.c + p[3], now.t + p[4] });
            }
        }
        pq.push({ now.a + 1, now.c, now.t + 1 });
        pq.push({ now.a, now.c + 1, now.t + 1 });
    }
}