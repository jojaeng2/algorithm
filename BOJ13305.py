import sys
input = sys.stdin.readline
n = int(input())
length = list(map(int,input().split()))
money = list(map(int,input().split()))
result = 0
mini = money[0]
for i in range(n-1):
    if i == 0:
        result += money[0] * length[0]
    else:
        mini = min(mini,money[i])
        result += mini*length[i]

print(result)
