import sys

input = sys.stdin.readline

def calculrate_score():
    global green, blue, score
    
    while 1:
        flag = True

        for i in range(6):
            if blue[0][5-i] != 0 and blue[1][5-i] != 0 and blue[2][5-i] != 0 and blue[3][5-i] != 0:
                score += 1

                





                flag = False
                break

        if flag:
            break

  

def remove_overflow():
    global green, blue

    blue_over, green_over = 0, 0

    for i in range(2):
        g_flag, b_flag = False, False
        for j in range(4):
            if blue[j][i] > 0:
                flag = True
            if green[j][i] > 0:
                flag = True
        if b_flag:
            blue_over += 1
        if g_flag:
            green_over += 1

    for i in range(4):
        for _ in range(blue_over):
            del blue[-1]
            blue = [0] + blue
        for _ in range(green_ove):
            del green[-1]
            green = [0] + green
    

def move_block(block, n):
    global green, blue

    kind, x, y = block

    if kind == 1:
        for i in range(7):
            if i == 6:
                blue[x][5] = n
                break
            if blue[x][i] != 0:
                blue[x][i-1] = n
                break
        for i in range(7):
            if i == 6:
                green[3-y][5] = n
                break
            if green[3-y][i] != 0:
                green[3-y][i-1] = n
                break

    elif kind == 2:
        for i in range(7):
            if i == 6:
                blue[x][4], blue[x][5] = n, n
                break
            if blue[x][i] != 0:
                blue[x][i-1], blue[x][i-2] = n, n
                break
        for i in range(7):
            if i == 6:
                green[3-y][5], green[2-y][5] = n, n
                break
            if green[3-y][i] != 0 or green[2-y][i] != 0:
                green[3-y][i-1], green[2-y][i-1] = n, n
                break

    elif kind == 3:
        for i in range(7):
            if i == 6:
                blue[x][5], blue[x+1][5] = n, n
                break
            if blue[x][i] != 0 or blue[x+1][i] != 0:
                blue[x][i-1], blue[x+1][i-1] = n, n
                break
        for i in range(7):
            if i == 6:
                green[3-y][4], green[3-y][5] = n, n
                break
            if green[3-y] != 0:
                green[3-y][i-1], green[3-y][i-2] = n, n
                break

if __name__ == '__main__':

    N = int(input())
    blocks = [list(map(int, input().split())) for _ in range(N)]

    blue = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]
    green = [[0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0], [0, 0, 0, 0, 0, 0]]

    score = 0

    for i, block in enumerate(blocks):
        move_block(block, i+1)
        #calculrate_score()
        #remove_overflow()

    print('----------------')
    for i in blue:
        print(i)
    print('----------------')
    for i in green:
        print(i)
    print('----------------')


    """
    sum = 0
    for i in range(4):
        for j in range(6):
            if blue[i][j] == 1:
                sum += 1
            if green[i][j] == 1:
                sum += 1

    print(score)
    print(sum)
    """