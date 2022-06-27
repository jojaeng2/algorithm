import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
dat = [0 for i in range(1000001)]
for i in num:
    dat[i] += 1
result = [-1 for i in range(n)]
stack = []
for i in range(n-1,-1,-1):
    while stack:
        if dat[stack[-1]] <= dat[num[i]]:
            stack.pop()
        else:
            break
    if len(stack) == 0:
        pass
    else:
        result[i] = stack[-1]
    stack.append(num[i])
for i in result:
    print(i,end = " ")