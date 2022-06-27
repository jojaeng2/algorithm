import sys
from collections import deque

n = int(input())
bfs = []
visit = []
for i in range(n):
    bfs.append(list(map(str,input())))
    visit.append([0]*n)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
sum,result = 0,0
dq = deque([[0,0]])
def ans(i,j,sum,visit):
for i in range(n):
    for j in range(n):
        if visit[i][j] == 0:
            dq.append([i,j])
            sum += 1
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if bfs[nx][ny] == bfs[x][y] and visit[nx][ny] == 0:
                            visit[nx][ny] = 1
                            dq.append([nx,ny])
change = bfs
for i in range(n):
    for j in range(n):
        if change[i][j] == "G":
            change[i][j] = "R"
red = []
for i in range(n):
    red.append([0]*n)
for i in range(n):
    for j in range(n):
        if red[i][j] == 0:
            dq.append([i,j])
            result += 1
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if change[nx][ny] == change[x][y] and red[nx][ny] == 0:
                            red[nx][ny] = 1
                            dq.append([nx,ny])
print(sum,result)
