import sys
input = sys.stdin.readline
n = int(input())
k = int(input())
num = list(map(int,input().split()))
num.sort()
dat = []
for i in range(n-1):
    dat.append(num[i+1]-num[i])
dat.sort()
for i in range(k-1):
    dat.pop()
print(sum(dat))