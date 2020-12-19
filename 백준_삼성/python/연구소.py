import sys
import copy

input = sys.stdin.readline

N, M = [int(i) for i in str(input()).split()]

Map, virus = [], []
for _ in range(N):
    Map.append([int(i) for i in str(input()).split()])

safe_area = 0
for i in range(N):
    for j in range(M):
        if Map[i][j] == 2:
            virus.append((i, j))
        elif Map[i][j] == 0:
            safe_area += 1


def infect_virus(): 
    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    case, changed = copy.deepcopy(virus), copy.deepcopy(Map)
    count = 0

    while case:
        pos = case.pop()
      
        for i in range(4):
            nx = pos[0] + dx[i]
            ny = pos[1] + dy[i]

            if nx >=0 and nx < N and ny >= 0 and ny < M:
                if changed[nx][ny] == 0:
                    changed[nx][ny] = 2
                    case.append((nx, ny))
                    count += 1
    
    return safe_area - count - 3

answer = 0

def make_wall(s, count):
    global answer

    if count >= 3:
        answer = max(answer, infect_virus())
        return 0

    for x in range(s, N*M):
        i = x // M
        j = x % M

        if Map[i][j] == 0:
            Map[i][j] = 1
            make_wall(s + 1, count + 1)
            Map[i][j] = 0
    return 0

make_wall(0, 0)
print(answer)