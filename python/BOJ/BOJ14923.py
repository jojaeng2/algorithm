from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
x1,y1 = map(int,input().split())
x2,y2 = map(int,input().split())
graph = [[0 for i in range(m+1)]]
for i in range(n):
    graph.append([0]+list(map(int,input().split())))
visit = [[[0,0] for i in range(m+1)]for j in range(n+1)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
dq = deque([[x1,y1,0]])
visit[x1][y1][0],visit[x1][y1][1] = 1,1
while dq:
    a = dq.popleft()
    x,y,breaked = a[0],a[1],a[2]
    if x == x2 and y == y2:
        break
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 1 <= nx < n+1 and 1 <= ny < m+1:
            if breaked == 0 and visit[nx][ny][0] == 0 and graph[nx][ny] == 0:
                dq.append([nx,ny,0])
                visit[nx][ny][0] = visit[x][y][0] + 1
            elif breaked == 0 and visit[nx][ny][1] == 0 and graph[nx][ny] == 1:
                dq.append([nx,ny,1])
                visit[nx][ny][1] = visit[x][y][0] + 1
            elif breaked == 1 and visit[nx][ny][1] == 0 and graph[nx][ny] == 0:
                dq.append([nx,ny,1])
                visit[nx][ny][1] = visit[x][y][1] + 1
if visit[x2][y2][0] == 0:
    visit[x2][y2][0] = 1000001
if visit[x2][y2][1] == 0:
    visit[x2][y2][1] = 1000001
result = min(visit[x2][y2])
if result == 1000001:
    print(-1)
else:
    print(result-1)