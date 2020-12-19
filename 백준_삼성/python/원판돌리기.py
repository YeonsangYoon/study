import sys

input = sys.stdin.readline


def rotate_circle(xi, di, ki):
    global circle

    for i in range(1, n+1):
        if i % xi == 0:
            if di == 1:      
                circle[i-1] = circle[i-1][ki:] + circle[i-1][:ki]
            else:           
                circle[i-1] = circle[i-1][-ki:] + circle[i-1][:-ki]

    flag = False
    for i in range(n):
        for j in range(m):
            for p in range(2):
                ni, nj = i + dx[p], j + dy[p]
                if ni < n and ni >= 0 and nj < m:
                    if abs(circle[i][j]) == abs(circle[ni][nj]) and circle[i][j] != 0:
                        if circle[i][j] > 0:
                            circle[i][j] *= -1
                        if circle[ni][nj] > 0:
                            circle[ni][nj] *= -1
                        flag = True

    for i in range(n):
        for j in range(m):
            if circle[i][j] < 0:
                circle[i][j] = 0
    
    if not flag:
        sum, cnt = 0, 0
        for i in range(n):
            for j in range(m):
                if circle[i][j] != 0:
                    sum += circle[i][j]
                    cnt += 1
        if cnt == 0:
            return False
        avg = sum / cnt

        for i in range(n):
            for j in range(m):
                if circle[i][j] > 0:
                    if circle[i][j] > avg:
                        circle[i][j] -= 1
                    elif circle[i][j] < avg:
                        circle[i][j] += 1

    return True


if __name__ == "__main__":

    n, m, T = map(int, input().split())
    circle = [list(map(int, input().split())) for _ in range(n)]
    x, d, k = [], [], []
    for _ in range(T):
        tmp = list(map(int, input().split()))
        x.append(tmp[0])
        d.append(tmp[1])
        k.append(tmp[2])

    dx = [0, -1]
    dy = [-1, 0]

    flag = True
    for i in range(T):   
        flag = rotate_circle(x[i], d[i], k[i])
        if not flag:
            break

    sum = 0
    for i in circle:
        for j in i:
            sum += j
    print(sum)