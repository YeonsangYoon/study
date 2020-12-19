import sys
from copy import deepcopy
from collections import deque

input = sys.stdin.readline


def activate(idx, count):
    global visited, combination

    if count == M:
        comb = []
        for i in range(virus_cnt):
            if visited[i] == True:
                comb.append(virus[i])
        combination.append(comb)

    for i in range(idx, virus_cnt):
        if not visited[i]:
            visited[i] = True
            activate(i + 1, count + 1)
            visited[i] = False


def spread_virus(act):
    cp_map = deepcopy(Map)

    for i in range(N):
        for j in range(N):
            if cp_map[i][j] == 2:
                cp_map[i][j] = -100
            elif cp_map[i][j] == 1:
                cp_map[i][j] = -200
            else:
                cp_map[i][j] = 'o'

    for x, y in act:
        cp_map[x][y] = 0

    queue = deque(act)

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif cp_map[nx][ny] == -200:
                continue
            elif cp_map[nx][ny] == -100 or cp_map[nx][ny] == 'o':
                if Map[nx][ny] == 2:
                    cp_map[nx][ny] = -(abs(cp_map[x][y]) + 1)
                    queue.append((nx,ny))
                else:
                    cp_map[nx][ny] = abs(cp_map[x][y]) + 1
                    queue.append((nx,ny))

    time = 0
    for i in range(N):
        for j in range(N):
            if cp_map[i][j] == 'o':
                return sys.maxsize
            time = max(time, cp_map[i][j])

    return time


if __name__ == "__main__":

    N, M = map(int, input().split())
    Map = [list(map(int, input().split())) for _ in range(N)]
    virus = []
    for i in range(N):
        for j in range(N):
            if Map[i][j] == 2:
                virus.append((i, j))

    virus_cnt = len(virus)
    visited = [False]*virus_cnt
    combination = []

    activate(0, 0)

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    ans = sys.maxsize
    for comb in combination:
        ans = min(ans, spread_virus(comb))

    if ans == sys.maxsize:
        print(-1)
    else:
        print(ans)