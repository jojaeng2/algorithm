import sys
input = sys.stdin.readline
sys.setrecursionlimit(1000000)
n,m = map(int,input().split())
dat = [i for i in range(n+1)]
def find(target):
    if target == dat[target]:
        return target
    dat[target] = find(dat[target])
    return dat[target]
def union(a,b):
    a = find(a)
    b = find(b)
    if a < b:
        dat[b] = a
    else:
        dat[a] = b

for i in range(m):
    a,b,c = map(int,input().split())
    if a == 1:
        if find(b) == find(c):
            print("YES")
        else:
            print("NO")
    else:
        union(b,c)