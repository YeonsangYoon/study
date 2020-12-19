import sys
input = sys.stdin.readline

from copy import deepcopy
from collections import deque

def find_fish():
    global shark, eat_cnt, time

    cpmap = []
    for _ in range(N):
        cpmap.append([])
        for _ in range(N):
            cpmap[-1].append(0)

    for i in range(N):
        for j in range(N):
            if Map[i][j] != 9 and Map[i][j] > shark[2]:
                cpmap[i][j] = -1

    pos = shark[:2]
    queue = deque([pos])

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif nx == pos[0] and ny == pos[1]:
                continue
            elif cpmap[nx][ny] == -1:
                continue
            elif cpmap[nx][ny] == 0:
                cpmap[nx][ny] = cpmap[x][y] + 1
                queue.append([nx, ny])

    near = sys.maxsize
    for x, y, size in fish:
        if cpmap[x][y] != -1 and cpmap[x][y] != 0 and shark[2] > size:
            if near > cpmap[x][y]:
                near = cpmap[x][y]
                selected = [x, y, size]

    if near == sys.maxsize:
        return False
    else:
        time += near
        eat_cnt += 1
        fish.remove(selected)
        if shark[2] == eat_cnt:
            shark = [selected[0], selected[1], shark[2]+1]
            eat_cnt = 0
        else:
            shark = [selected[0], selected[1], shark[2]]
        return True

if __name__ == "__main__":

    N = int(input())
    Map = [list(map(int, input().split())) for _ in range(N)]

    fish = []
    for i in range(N):
        for j in range(N):
            if Map[i][j] == 9:
                shark = [i, j, 2]
            elif Map[i][j] != 0:
                fish.append([i, j, Map[i][j]])
    fish.sort()

    time = 0
    eat_cnt = 0

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    
    while find_fish():
        pass

    print(time)

    