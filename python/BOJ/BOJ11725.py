import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline

n = int(input())
tree = [[]for i in range(n+1)]
for i in range(n-1):
    a,b = map(int,input().split())
    tree[a].append(b)
    tree[b].append(a)
visit = [0 for i in range(n+1)]

def dfs(start,tree,visit):
    for i in tree[start]:
        if visit[i] == 0:
            visit[i] = start
        dfs(i,tree,visit)
dfs(1,tree,visit)
for i in range(2,n+1):
    print(visit[i])