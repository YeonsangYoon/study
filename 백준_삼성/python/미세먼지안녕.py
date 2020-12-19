import sys

input = sys.stdin.readline

def clean_dust():
    global room

    for i in range(cleaner):
        room[cleaner - i][0] = room[cleaner - i - 1][0]

    room[0].pop(0)
    room[0].append(room[1][C-1])

    for i in range(cleaner):
        room[i][C-1] = room[i+1][C-1]

    room[cleaner].pop(-1)
    room[cleaner] = [-1] + room[cleaner]
    room[cleaner][1] = 0

    for i in range(R - cleaner - 2):
        room[cleaner+1 + i][0] = room[cleaner+2 + i][0]

    room[R-1].pop(0)
    room[R-1].append(room[R-2][C-1])

    for i in range(R - cleaner - 2):
        room[R-1 - i][C-1] = room[R-1 - i - 1][C-1]

    room[cleaner+1].pop(-1)
    room[cleaner+1] = [-1] + room[cleaner+1]
    room[cleaner+1][1] = 0



def spread_dust():
    global room

    dusts = []
    for i in range(R):
        for j in range(C):
            if room[i][j] != 0 and room[i][j] != -1:
                dusts.append([i, j, room[i][j]])

    for x, y, size in dusts:
        cnt = 0
        for i in range(4):
            nx, ny = x + dx[i], y + dy[i]
            sd = size // 5

            if nx < 0 or nx >= R or ny < 0 or ny >= C:
                continue
            elif room[nx][ny] == -1:
                continue
            room[nx][ny] += sd
            cnt += 1

        room[x][y] -= (size // 5) * cnt


if __name__ == '__main__':

    R, C, T = map(int, input().split())
    room = [list(map(int, input().split())) for _ in range(R)]
    for i in range(R):
        if room[i][0] == -1:
            cleaner = i
            break

    dx = [0, 0, 1, -1]
    dy = [1, -1, 0, 0]

    for _ in range(T):
        spread_dust()
        clean_dust()

    ans = 0

    for i in range(R):
        for j in range(C):
            ans += room[i][j]

    print(ans+2)
