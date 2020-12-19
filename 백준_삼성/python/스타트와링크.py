import sys

input = sys.stdin.readline

def distribute_player(idx, count):
    global answer

    if count == N // 2:
        val = 0
        for i in range(N):
            for j in range(N):
                if start_team[i] and start_team[j]:
                    val += skill[i][j]
                elif not start_team[i] and not start_team[j]:
                    val -= skill[i][j]
        answer = min(answer, abs(val))

    for i in range(idx, N):
        if start_team[i]:
            continue
        start_team[i] = 1
        distribute_player(i + 1, count + 1)
        start_team[i] = 0

N = int(input())

skill = [list(map(int, input().split())) for _ in range(N)]

start_team = [0 for _ in range(N)]
answer = sys.maxsize

distribute_player(0, 0)

print(answer)