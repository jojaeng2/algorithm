import sys
from collections import deque
input = sys.stdin.readline
r,c = map(int,input().split())
bfs = []
water = []
visit = []
for i in range(r):
    bfs.append(list(map(str,input())))
    water.append([0]*c)
    visit.append([0]*c)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
for i in range(r):
    for j in range(c):
        if bfs[i][j] == "*":
            dq.append([i,j])
            water[i][j] = 1
        if bfs[i][j] == "S":
            s = [i,j]
            visit[i][j] = 1
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            if bfs[nx][ny] == "." and water[nx][ny] == 0:
                dq.append([nx,ny])
                water[nx][ny] = water[x][y] + 1
for i in range(r):
    for j in range(c):
        if water[i][j] == 0:
            water[i][j] = -1
        if bfs[i][j] == "D":
            d = [i,j]
dq.append(s)
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            if bfs[nx][ny] == "." and visit[nx][ny] == 0:
                if visit[x][y] + 1 < water[nx][ny] or water[nx][ny] == -1:
                    visit[nx][ny] = visit[x][y] + 1
                    dq.append([nx,ny])
result = []
x,y = d[0],d[1]
for i in range(4):
    nx = x + dx[i]
    ny = y + dy[i]
    if 0 <= nx < r and 0 <= ny < c:
        if visit[nx][ny] != 0:
            result.append(visit[nx][ny])
print(water)
print(visit)
if len(result) == 0:
    print("KAKTUS")
else:
    print(min(result))      