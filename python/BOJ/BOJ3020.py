import sys
input = sys.stdin.readline
n,h = map(int,input().split())
bottom = [0 for i in range(h+1)]
top = [0 for i in range(h+1)]
for i in range(n):
    num = int(input())
    if i % 2 == 0:
        bottom[num] += 1
    else:
        top[num] += 1
result = n // 2 + top[h]
dat = [0 for i in range(n+1)]
for i in range(1,h+1):
    result -= bottom[i-1] 
    result += top[h-(i-1)]
    dat[result] += 1
for i in range(len(dat)):
    if dat[i] != 0:
        print(i,dat[i])
        break
print(dat)