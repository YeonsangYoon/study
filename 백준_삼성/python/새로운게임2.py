import sys

input = sys.stdin.readline

def new_dir(dir):
    if dir == 0:
        return 1
    elif dir == 1:
        return 0
    elif dir == 2:
        return 3
    elif dir == 3:
        return 2

def move_horses():
    global board, horses

    for i in range(K):
        x, y, dir = horses[i][0], horses[i][1], horses[i][2]
        nx, ny = x + dx[dir], y + dy[dir]

        idx = board[x][y].index(i)

        if nx < 0 or nx >= N or ny < 0 or ny >= N:
            nd = new_dir(dir)
            horses[i][2] = nd
            nx, ny = x + dx[nd], y + dy[nd]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif chess[nx][ny] == 0:
                moved = board[x][y][idx:]
                board[x][y] = board[x][y][:idx]
                board[nx][ny] += moved
                for horse in moved:
                    horses[horse][0], horses[horse][1] = nx, ny
            elif chess[nx][ny] == 1:
                moved = list(reversed(board[x][y][idx:]))
                board[x][y] = board[x][y][:idx]
                board[nx][ny] += moved
                for horse in moved:
                    horses[horse][0], horses[horse][1] = nx, ny
            elif chess[nx][ny] == 2:
                continue

        elif chess[nx][ny] == 0:
            moved = board[x][y][idx:]
            board[x][y] = board[x][y][:idx]
            board[nx][ny] += moved
            for horse in moved:
                horses[horse][0], horses[horse][1] = nx, ny
        elif chess[nx][ny] == 1:
            moved = list(reversed(board[x][y][idx:]))
            board[x][y] = board[x][y][:idx]
            board[nx][ny] += moved
            for horse in moved:
                horses[horse][0], horses[horse][1] = nx, ny
        elif chess[nx][ny] == 2:
            nd = new_dir(dir)
            horses[i][2] = nd
            nx, ny = x + dx[nd], y + dy[nd]

            if nx < 0 or nx >= N or ny < 0 or ny >= N:
                continue
            elif chess[nx][ny] == 0:
                moved = board[x][y][idx:]
                board[x][y] = board[x][y][:idx]
                board[nx][ny] += moved
                for horse in moved:
                    horses[horse][0], horses[horse][1] = nx, ny
            elif chess[nx][ny] == 1:
                moved = list(reversed(board[x][y][idx:]))
                board[x][y] = board[x][y][:idx]
                board[nx][ny] += moved
                for horse in moved:
                    horses[horse][0], horses[horse][1] = nx, ny
            elif chess[nx][ny] == 2:
                continue

        if len(board[nx][ny]) >= 4:
            return True

    return False



if __name__ == '__main__':

    N, K = map(int, input().split())
    chess = [list(map(int, input().split())) for _ in range(N)]
    horses = []
    for i in range(K):
        x, y, dir = list(map(int, input().split()))
        horses.append([x-1, y-1, dir-1])

    board = []
    for _ in range(N):
        board.append([])
        for _ in range(N):
            board[-1].append([])

    for i in range(K):
        x, y = horses[i][0], horses[i][1]
        board[x][y].append(i)

    dx = [0, 0, -1, 1]
    dy = [1, -1, 0, 0]


    count = 1

    while count <= 1000:
        if move_horses():
            print(count)
            break
        count += 1

    if count > 1000:
        print(-1)
