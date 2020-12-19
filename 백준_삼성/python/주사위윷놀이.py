import sys 

input = sys.stdin.readline

special_case = {
    0 : [0, 0, 0, 0, 0, 0],
    -1 : [-1, 2, 4, 6, 8, 10],
    10 : [10, -13, -16, -19, -25, -30],
    20 : [20, -22, -24, -25, -30, -35],
    30 : [30, -28, -27, -26, -25, -30],
    32 : [32, 34, 36, 38, 40, 0],
    34 : [34, 36, 38, 40, 0, 0],
    36 : [36, 38, 40, 0, 0, 0],
    38 : [38, 40, 0, 0, 0, 0],
    40 : [40, 0, 0, 0, 0, 0],
    -13 : [13, -16, -19, -25, -30, -35],
    -16 : [-16, -19, -25, -30, -35, 40],
    -19 : [-19, -25, -30, -35, 40, 0],
    -22 : [-22, -24, -25, -30, -35, 40],
    -24 : [-24, -25, -30, -35, 40, 0],
    -25 : [-25, -30, -35, 40, 0, 0],
    -26 : [-26, -25, -30, -35, 40, 0],
    -27 : [-27, -26, -25, -30, -35, 40,],
    -28 : [-28, -27, -26, -25, -30, -35],
    -30 : [-30, -35, 40, 0, 0, 0],
    -35 : [-35, 40, 0, 0, 0, 0],
    }

def move_horse(start, cnt):

    if start in special_case:
        return special_case[start][cnt]
    else:
        return start + 2 * cnt

def dfs(idx, score):
    global ans, horses

    if idx >= 10:
        ans = max(ans, score)
        return
    
    for i in range(4):
        tmp = horses[i]
        next = move_horse(horses[i], dice[idx])
        if (next in horses and next != 0) or tmp == 0:
            continue

        horses[i] = next
        dfs(idx + 1, score + abs(next))
        horses[i] = tmp

if __name__ == '__main__':

    horses = [-1, -1, -1, -1]
    dice = list(map(int, input().split()))

    ans = 0
    dfs(0, 0)
    print(ans)