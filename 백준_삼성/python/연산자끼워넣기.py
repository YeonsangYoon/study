import sys

input = sys.stdin.readline

def recursion(count, result):
    global max_val, min_val

    if count == N-1:
        max_val = max(max_val, result)
        min_val = min(min_val, result)
        return

    for key in operator.keys():
        if key == 'plus' and operator[key] > 0:
            operator[key] -= 1
            recursion(count+1, result + num[count+1])
            operator[key] += 1
        elif key == 'minus' and operator[key] > 0:
            operator[key] -= 1
            recursion(count+1, result - num[count+1])
            operator[key] += 1
        elif key == 'mult' and operator[key] > 0:
            operator[key] -= 1
            recursion(count+1, result * num[count+1])
            operator[key] += 1
        elif key == 'div' and operator[key] > 0:
            operator[key] -= 1
            if result > 0 and num[count + 1] > 0:
                recursion(count+1, result // num[count+1])
            elif result < 0 and num[count + 1] > 0:
                recursion(count+1, -(-result // num[count+1]))
            elif result > 0 and num[count + 1] < 0:
                recursion(count+1, -(result // -num[count+1]))
            else:
                recursion(count+1, -result // -num[count+1])
            operator[key] += 1



if __name__ == "__main__":
    
    N = int(input())

    num = [int(i) for i in str(input()).split()]

    operator = {'plus' : 0, 'minus' : 0, 'mult' : 0, 'div' : 0}
    tmp = [int(i) for i in str(input()).split()]   
    for i, key in enumerate(operator.keys()):
        operator[key] = tmp[i]


    min_val = 1000000000
    max_val = -1000000000

    recursion(0, num[0])

    print(max_val)
    print(min_val)