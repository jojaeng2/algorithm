import sys
input = sys.stdin.readline
t = int(input())

def find(target):
    if target == dat[target]:
        return target
    dat[target] = find(dat[target])
    return dat[target]

def union(x,y):
    x = find(x)
    y = find(y)
    if x < y:
        dat[y] = dat[x]
        cnt[x] += cnt[y]
    else:
        dat[x] = dat[y]
        cnt[y] += cnt[x]

for i in range(t):
    n = int(input())
    dat = [i for i in range(2*n+1)]
    dic = {}
    index = 1
    cnt = [1 for i in range(2*n+1)]
    for j in range(n):
        a,b = map(str,input().split())
        if a not in dic:
            dic[a] = index
            index += 1
        if b not in dic:
            dic[b] = index
            index += 1
        if find(dic[a]) != find(dic[b]):
            union(dic[a],dic[b])
        print(cnt)
        print(cnt[find(min(dic[a],dic[b]))])