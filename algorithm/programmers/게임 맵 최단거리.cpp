#include <bits/stdc++.h>
using namespace std;

int n, m;
int dr[4] = { 0, 0, 1, -1 };
int dc[4] = { 1, -1, 0, 0 };
int dist[101][101];

int solution(vector<vector<int> > maps)
{
    n = (int)maps.size();
    m = (int)maps[0].size();

    queue<pair<int, int>> q;
    q.push({ 0, 0 });

    while (!q.empty()) {
        pair<int, int> now = q.front(); q.pop();

        for (int i = 0; i < 4; i++) {
            int nr = now.first + dr[i];
            int nc = now.second + dc[i];

            if (nr < 0 || nr >= n || nc < 0 || nc >= m)
                continue;
            else if (maps[nr][nc] == 0 || dist[nr][nc] > 0)
                continue;

            dist[nr][nc] = dist[now.first][now.second] + 1;
            q.push({ nr, nc });
        }
    }

    if (dist[n - 1][m - 1] > 0)
        return dist[n - 1][m - 1] + 1;
    else
        return -1;
}