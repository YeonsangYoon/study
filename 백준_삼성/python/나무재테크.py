import sys
input = sys.stdin.readline


def solve():
    global Map, tree, die_tree

    die_tree = []

    # spring
    for i, t in enumerate(tree):
        x, y, age = t

        if Map[x][y] >= age:
            Map[x][y] -= age
            tree[i][2] += 1
        else:
            die_tree.append([x, y, age])

    for t in die_tree:
        tree.remove(t)

    # summer
    for i in range(len(die_tree)):
        x, y, age = die_tree[i]
        Map[x][y] += age // 2

    # fall
    for i, t in enumerate(tree):
        x, y, age = t
        if age % 5 == 0:
            for i in range(8):
                nx, ny = x + dx[i], y + dy[i]
                if nx < 0 or nx >= N or ny < 0 or ny >= N:
                    continue

                tree = [[nx, ny, 1]] + tree
                #tree.insert(0, [nx, ny, 1])

    # winter
    for i in range(N):
        for j in range(N):
            Map[i][j] += s2d2[i][j]


if __name__ == '__main__':


    N, M, K = map(int, input().split())
    s2d2 = [list(map(int, input().split())) for _ in range(N)]
    tree = [list(map(int, input().split())) for _ in range(M)]
    for i in range(M):
        tree[i][0] -= 1
        tree[i][1] -= 1
    tree.sort(key = lambda x : x[2])

    Map = []
    for _ in range(N):
        Map.append([])
        for _ in range(N):
            Map[-1].append(5)

    dx = [0, 0, 1, -1, 1, 1, -1, -1]
    dy = [1, -1, 0, 0, -1, 1, -1, 1]

    for _ in range(K):
        solve()

    print(len(tree))

  