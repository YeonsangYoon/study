import sys

input = sys.stdin.readline

def get_combination():
    combination = []

    for x in range(N):
        for y in range(N):
            for d1 in range(N):
                for d2 in range(N):
                    if x >=0 and x + d1 + d2 > x and N-1 >= x + d1 + d2 \
                        and y - d1 >= 0 and y > y - d1 and y + d2 > y and N-1 >= y + d2:
                        combination.append([x, y, d1, d2])

    return combination

def make_votezoon(comb):
    x, y, d1, d2 = comb
    zoon = []

    for _ in range(N):
        zoon.append([])
        for _ in range(N):
            zoon[-1].append(1)

    for i in range(d1+1):
        for j in range(d2+1):
            zoon[x+i+j][y-i+j] = 5
            if i != 0 and j != 0:
                zoon[x+i+j-1][y-i+j] = 5

    for i in range(N):
        for j in range(N):
            if zoon[i][j] != 5:
                if i >= 0 and i < x+d1 and j >= 0 and j <= y:
                    zoon[i][j] = 1
                elif i >= 0 and i <= x+d2 and j > y and j <= N-1:
                    zoon[i][j] = 2
                elif i >= x+d1 and i <= N-1 and j >= 0 and j < y-d1+d2:
                    zoon[i][j] = 3
                elif i > x+d2 and i <= N-1 and j >= y-d1+d2 and j <= N-1:
                    zoon[i][j] = 4

    return zoon

def calculrate(map):
    zoon = [0, 0, 0, 0, 0]

    for i in range(N):
        for j in range(N):
            zoon[map[i][j]-1] += city[i][j]

    return max(zoon) - min(zoon)


if __name__ == '__main__':

    N = int(input())
    city = [list(map(int, input().split())) for _ in range(N)]

    comb = get_combination()

    ans = sys.maxsize

    for i in comb:
        ans = min(ans, calculrate(make_votezoon(i)))

    print(ans)