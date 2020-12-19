
money = int(input())
N = int(input())
cost = list(map(int, input().split()))

sum_cost = sum(cost)

if sum_cost > money-40:
    print("impossible")
else:
    print("possible")