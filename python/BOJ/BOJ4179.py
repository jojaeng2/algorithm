import sys
from collections import deque
input = sys.stdin.readline
r,c = map(int,input().split())
bfs = []
visit = []
fire = []
for i in range(r):
    bfs.append(list(map(str,input())))
    visit.append([0]*c)
    fire.append([0]*c)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
for i in range(r):
    for j in range(c):
        if bfs[i][j] == "F":
            dq.append([i,j])
            fire[i][j] = 1
        if bfs[i][j] == "J":
            J = [i,j]
            visit[i][j] = 1
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            if bfs[nx][ny] == "." and fire[nx][ny] == 0:
                fire[nx][ny] = fire[x][y] + 1
                dq.append([nx,ny])
for i in range(r):
    for j in range(c):
        if fire[i][j] == 0:
            fire[i][j] = -1                
dq.append(J)
result = -1
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    if result != -1:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < r and 0 <= ny < c:
            if bfs[nx][ny] == "." and visit[nx][ny] == 0:
                if visit[x][y] + 1 < fire[nx][ny] or fire[nx][ny] == -1:
                    visit[nx][ny] = visit[x][y] + 1
                    dq.append([nx,ny])
        else:
            if bfs[x][y] == "." or bfs[x][y] == "J":
                result = visit[x][y]
                break                
print(fire)
print(visit)   
if result == -1:
    print("IMPOSSIBLE")
else:
    print(result)                