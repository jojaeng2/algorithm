import sys
input = sys.stdin.readline
n,m = map(int,input().split())
num = [0 for i in range(n+1)]
log = [i for i in range(n+1)]
for i in range(1,n+1):
    num[i] = int(input())
def find(target):
    if target == log[target]:
        return target
    log[target] = find(log[target])
    return log[target]

def union(a,b):
    a = find(a)
    b = find(b)
    if a == 0 or b == 0:
        pass
    else:
        if num[a] < num[b]:
            num[b] -= num[a]
            log[a] = log[b]
        elif num[a] > num[b]:
            num[a] -= num[b]
            log[b] = log[a]
        elif num[a] == num[b]:
            num[a],num[b] = 0,0
            log[a],log[b] = 0,0

for i in range(m):
    a,b,c = map(int,input().split())
    if a == 2:
        union(b,c)
    else:
        x,y = find(b),find(c)
        if x != 0 and y != 0:
            if y < x:
                num[y] += num[x]
                log[x] = log[y]
            else:
                num[x] += num[y]
                log[y] = log[x]
result = []
for i in range(1,n+1):
    if i == log[i]:
        result.append(num[i])
result.sort()
print(len(result))
for i in result:
    print(i,end = " ")
