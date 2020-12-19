import sys
input = sys.stdin.readline


def get_position(info):
    r, c, s, d = info
    nd = d

    if d == 0:
        nc = c
        ns = s % ((R - 1) * 2)
        x, y = ((r - ns) + (R - 1) * 2) // (R - 1), ((r - ns) + (R - 1) * 2) % (R - 1) 
        if x % 2 != 0:
            nr = R - 1 - y
            nd = 1
        else:
            nr = y

    elif d == 1:
        nc = c
        ns = s % ((R - 1) * 2)
        x, y = (r + ns) // (R - 1), (r + ns) % (R - 1)
        if x % 2 != 0:
            nr = R - 1 - y
            nd = 0
        else:
            nr = y

    elif d == 2:
        nr = r
        ns = s % ((C - 1) * 2)
        x, y = (c - 1 + ns) // (C - 1), (c - 1 + ns) % (C - 1)
        if x % 2 != 0:
            nc = C - y
            nd = 3
        else:
            nc = y + 1

    elif d == 3:
        nr = r
        ns = s % ((C - 1) * 2)
        x, y = (c - 1 - ns + (C - 1) * 2) // (C - 1), (c - 1 - ns + (C - 1) * 2) % (C - 1)
        if x % 2 != 0:
            nc = C - y
            nd = 2
        else:
            nc = y + 1

    return [nr, nc, s, nd]


def move_shark():
    global sea

    for shark, info in sharks.items():
        new = get_position(info)
        sharks[shark] = new

        sea[info[0]][info[1]].remove(shark)
        sea[new[0]][new[1]].append(shark)

    for i in range(R):
        for j in range(C+2):
            if len(sea[i][j]) >= 2:
                max_shark = max(sea[i][j])
                for s in sea[i][j]:
                    if s != max_shark:
                        del sharks[s]
                sea[i][j] = [max_shark]

def fising_king():
    global ans
    cur_pos = 0

    for _ in range(C):
        cur_pos += 1

        for i in range(R):
            if sea[i][cur_pos]:
                ans += sea[i][cur_pos][0]
                del sharks[sea[i][cur_pos][0]]
                sea[i][cur_pos] = []
                break

        move_shark()

if __name__ == '__main__':

    R, C, M = map(int, input().split())
    tmp = [list(map(int, input().split())) for _ in range(M)]
    for i in range(M):
        tmp[i][0] -= 1 
        tmp[i][3] -= 1

    # sharks 초기화
    sharks = {}
    for i in tmp:
        sharks[i[4]] = i[:4]

    # sea 초기화
    sea = []
    for _ in range(R):
        sea.append([])
        for _ in range(C+2):
            sea[-1].append([])
    for shark in tmp:
        sea[shark[0]][shark[1]].append(shark[4])

    dr = [-1, 1, 0, 0]
    dc = [0, 0, 1, -1]

    # 로직 시작
    ans = 0
    fising_king()
    print(ans)