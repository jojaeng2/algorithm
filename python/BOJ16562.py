import sys

input = sys.stdin.readline
n,m,k = map(int,input().split())
money = [0] + list(map(int,input().split()))
li = [i for i in range(n+1)]

def find(target):
    if target == li[target]:
        return target
    li[target] = find(li[target])
    return li[target]

def union(a,b):
    a = find(a)
    b = find(b)
    if money[a] < money[b]:
        li[b] = li[a]
    else:
        li[a] = li[b]

for i in range(m):
    a,b = map(int,input().split())
    union(a,b)
result = 0
for i in range(n+1):
    if i == li[i]:
        result += money[i]
    if k - result < 0:
        break
    
if k - result < 0:
    print("Oh no")
else:
    print(result)