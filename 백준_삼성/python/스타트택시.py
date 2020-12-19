import sys
from collections import deque
from copy import deepcopy
input = sys.stdin.readline


def find_customer():
    global fuel, taxi

    cpmap = deepcopy(Map)
 
    queue = deque([taxi])

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif nx == taxi[0] and ny == taxi[1]:
                continue
            elif cpmap[nx][ny] == -1:
                continue
            elif cpmap[nx][ny] == 0:
                cpmap[nx][ny] = cpmap[x][y] + 1
                queue.append([nx, ny])

    path = sys.maxsize
    for x, y, e1, e2 in customer:
        if cpmap[x][y] == 0 and (taxi[0] != x or taxi[1] != y):
            return False
        if path > cpmap[x][y]:
            path = cpmap[x][y]
            near = [x, y]

    if fuel <= path:
        return False

    taxi = near
    fuel -= path

    return True


def go_destination(d):
    global fuel, taxi

    cpmap = deepcopy(Map)
 
    queue = deque([taxi])

    while queue:
        x, y = queue.popleft()

        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif nx == taxi[0] and ny == taxi[1]:
                continue
            elif cpmap[nx][ny] == -1:
                continue
            elif cpmap[nx][ny] == 0:
                cpmap[nx][ny] = cpmap[x][y] + 1
                queue.append([nx, ny])

    path = cpmap[d[0]][d[1]]

    if path > fuel or cpmap[d[0]][d[1]] == 0:
        return False

    customer.remove([taxi[0], taxi[1], d[0], d[1]])
    fuel += path
    taxi = d

    return True


if __name__ == "__main__":

    N, M, fuel = map(int, input().split())
    Map = [list(map(int, input().split())) for _ in range(N)]
    for i in range(N):
        for j in range(N):
            if Map[i][j] == 1:
                Map[i][j] = -1

    taxi = list(map(int, input().split()))
    taxi[0] -= 1
    taxi[1] -= 1

    customer = [list(map(int, input().split())) for _ in range(M)]
    customer.sort()
    for i in range(M):
        for j in range(4):
            customer[i][j] -= 1

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    flag = False
    for i in range(M):
        if not find_customer():
            print(-1)
            flag = True
            break

        for x, y, d1, d2 in customer:
            if x == taxi[0] and y == taxi[1]:
                des = [d1, d2]

        if not go_destination(des):
            print(-1)
            flag = True
            break

    if not flag:
        print(fuel)