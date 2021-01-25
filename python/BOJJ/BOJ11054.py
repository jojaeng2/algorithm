import sys
n = int(input())
a = list(map(int,sys.stdin.readline().split()))
b = [1]*n
c = []
for i in range(n-1,-1,-1):
    c.append(a[i])
d = [1]*n
for i in range(1,n):
    for k in range(i):
        if a[i] > a[k]:
            b[i] = max(b[i],b[k]+1)
for i in range(1,n):
    for p in range(i):
        if c[i] > c[p]:
            d[i] = max(d[i],d[p]+1)
result = []
for i in range(n):
    result.append(b[i]+d[n-1-i]-1)
print(max(result))
