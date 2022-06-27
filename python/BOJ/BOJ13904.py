import sys
input = sys.stdin.readline
n = int(input())
num = []
for i in range(n):
    num.append(list(map(int,input().split())))
num.sort(key=lambda x:(-x[0],-x[1]))
result = 0
for i in range(n,0,-1):
    dat = [0,0]
    for j in range(n):
        if num[j][0] >= i and num[j][1] != 0:
            if dat[1] < num[j][1]:
                dat = [j,num[j][1]]
        elif num[j][0] < i:
            break
    if dat[1] != 0:
        result += dat[1]
        num[dat[0]][1] = 0
print(result)