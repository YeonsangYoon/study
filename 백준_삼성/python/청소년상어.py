import sys
from copy import deepcopy
input = sys.stdin.readline

def move_shark(x, y, eat):
    global ans, board, fish_pos

    eat, dir = eat_fish(x, y, eat)
    ans = max(ans, eat)
   
    move_fish(x, y)

    copy_fish_pos = deepcopy(fish_pos)
    copy_board = deepcopy(board)


    for i in range(1, 4):
        nx, ny = x + dx[dir]*i, y + dy[dir]*i

        if nx < 0 or nx >= 4 or ny < 0 or ny >= 4:
            break
        elif board[nx][ny][0] == 0:
            continue

        move_shark(nx, ny, eat)
        board = copy_board
        fish_pos = copy_fish_pos


def eat_fish(x, y, eat):
    global board

    eat += board[x][y][0]
    del fish_pos[board[x][y][0]]
    dir = board[x][y][1]
    board[x][y] = [0,0]

    return eat, dir

def move_fish(r, c):
    global board, fish_pos

    for i in range(1, 17):
        if i not in fish_pos:
            continue

        x, y = fish_pos[i][0], fish_pos[i][1]
        dir = board[x][y][1]

        nx, ny = x + dx[dir], y + dy[dir]

        while nx < 0 or nx >= 4 or ny < 0 or ny >= 4 or (nx == r and ny == c):
            dir = (dir + 1) % 8
            nx, ny = x + dx[dir], y + dy[dir]

        fish_pos[board[x][y][0]] = [nx, ny]
        if board[x][y][0] != 0:
            fish_pos[board[nx][ny][0]] = [x, y]

        tmp = board[nx][ny]
        board[nx][ny] = [board[x][y][0], dir]
        board[x][y] = tmp

if __name__ == '__main__':

    fish_pos = {}
    board = []
    for i in range(4):
        board.append([])
        tmp = list(map(int, input().split()))
        for j in range(4):
            board[-1].append([tmp[2*j], tmp[2*j+1]-1])
            fish_pos[tmp[j*2]] = [i, j]
 
    dx = [-1, -1, 0, 1, 1, 1, 0, -1]
    dy = [0, -1, -1, -1, 0, 1, 1, 1]

    ans = 0
    move_shark(0, 0, 0)
    print(ans)