import sys
from collections import deque
input = sys.stdin.readline
m,n = map(int,input().split())
bfs = []
for i in range(m):
    bfs.append(list(map(str,input())))
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
result = 0
for i in range(m):
    for j in range(n):
        if bfs[i][j] == "L":
            visit = []
            for h in range(m):
                visit.append([0]*n)
            dq.append([i,j])
            visit[i][j] = 1
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < m and 0 <= ny < n:
                        if bfs[nx][ny] == "L" and visit[nx][ny] == 0:
                            visit[nx][ny] = visit[x][y] + 1
                            dq.append([nx,ny])
            for q in range(m):
                result = max(result,max(visit[q]))

print(result-1)
