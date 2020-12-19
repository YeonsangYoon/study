import sys

input = sys.stdin.readline


def solve():
    global A

    r_len = 0
    c_len = 0
    for i in A:
        r_len += 1
        for j in i:
            c_len += 1
    c_len = c_len // r_len

    if r_len >= c_len:  # R operation
        max_len = 0
        for i, row in enumerate(A):
            A[i] = Sort(row)
            max_len = max(max_len, len(A[i]))

        for i, row in enumerate(A):
            for _ in range(max_len - len(row)):
                A[i].append(0)

        if max_len > 100:
            for i, row in enumerate(A):
                A[i] = row[:100]

    else:               # C operation
        max_len = 0
        nA = []
        for i in range(c_len):
            column = []
            for j in range(r_len):
                column.append(A[j][i])
            
            nA.append(Sort(column))
            max_len = max(max_len, len(nA[-1]))

        for i in range(c_len):
            for _ in range(max_len - len(nA[i])):
                nA[i].append(0)
        
        if max_len > 100:
            max_len = 100
            for i, col in enumerate(nA):
                nA[i] = col[:100]

        A = []
        for i in range(max_len):
            A.append([])
            for j in range(c_len):
                A[-1].append(nA[j][i])



def Sort(before):
    before.sort(reverse = True)
    hash = {}
    for i in before:
        if i == 0:
            continue
        elif i not in hash:
            hash[i] = 1
        else:
            hash[i] += 1

    tmp = []
    for key, value in hash.items():
        tmp.append([key, value])

    tmp.sort(key = lambda x : x[0] + 1000 * x[1])
    
    ret_list = []
    for i in tmp:
        ret_list += i

    return ret_list



if __name__ == "__main__":

    r, c, k = map(int, input().split())
    r -= 1
    c -= 1

    A = []
    for _ in range(3):
        A.append(list(map(int, input().split())))


    flag = False
    time = 0

    while time <= 100:
        r_len, c_len = 0, 0
        for i in A:
            r_len += 1
            for j in i:
                c_len += 1
        c_len = c_len // r_len

        if r_len <= r or c_len <= c:
            time += 1
            solve()
            continue
        else:
            if A[r][c] == k:
                print(time)
                flag = True
                break
            else:
                time += 1
                solve()

    if not flag:
        print(-1)
  


