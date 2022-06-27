import sys
input = sys.stdin.readline
sys.setrecursionlimit(10**8)
n = int(input())
m = int(input())
dat = [i for i in range(n)]

def find(target):
    if target == dat[target]:
        return target
    dat[target] = find(dat[target])
    return dat[target]

def union(a,b):
    a = find(a)
    b = find(b)
    if a < b:
        dat[b] = dat[a]
    else:
        dat[a] = dat[b]
for i in range(n):
    li = list(map(int,input().split()))
    for j in range(n):
        if li[j] == 1:
            union(i,j)
trip = list(map(int,input().split()))
if m == 1:
    print("YES")
else:
    for i in range(1,m):
        if find(i) == find(i-1):
            if i == m-1:
                print("YES")
        else:
            print("NO")
            break