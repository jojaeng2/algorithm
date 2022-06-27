from collections import deque
import sys
input = sys.stdin.readline
n,m = map(int,input().split())
graph = [[0 for i in range(m+1)]]
for i in range(n):
    graph.append([0] + list(map(int,input().split())))
h,w,x1,y1,x2,y2 = map(int,input().split())
dx = [-1,0,1,0]
dy = [0,-1,0,1]
dq = deque([[x1,y1]])
visit = [[0 for i in range(m+1)]for j in range(n+1)]
visit[x1][y1] = 1
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    for i in range(4):
        bl = True
        if i == 0:
            for j in range(w):
                if 1 == x or graph[x-1][y+j] == 1:
                    bl = False
                    break
        elif i == 1:
            for j in range(h):
                if y == 1 or graph[x+j][y-1] == 1:
                    bl = False
                    break
        elif i == 2:
            for j in range(w):
                if x == n-h+1 or graph[x+h][y+j] == 1:
                    bl = False
                    break
        elif i == 3:
            for j in range(h):
                if y == m-w+1 or graph[x+j][y+w] == 1:
                    bl = False
                    break
        nx = x + dx[i]
        ny = y + dy[i]
        if bl == True and visit[nx][ny] == 0:    
            dq.append([nx,ny])
            visit[nx][ny] = visit[x][y] + 1
  
print(visit[x2][y2]-1)