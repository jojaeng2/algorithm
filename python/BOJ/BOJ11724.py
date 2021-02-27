from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
bfs = [[0 for i in range(n)]for j in range(n)]
visit = [0 for i in range(n)]
for i in range(m):
    a,b = map(int,input().split())
    bfs[a-1][b-1] = 1
    bfs[b-1][a-1] = 1
result = 0
def dfs(i):
    visit[i] = 1
    for k in range(n):
        if bfs[i][k] == 1 and visit[k] == 0:
            dfs(k) 
for i in range(n):
    if visit[i] == 0:
        result += 1
        dfs(i)
print(result)