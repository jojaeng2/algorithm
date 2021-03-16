from collections import deque
n,m,t = map(int,input().split())
graph = []
for i in range(n):
    graph.append(list(map(int,input().split())))
visit = [[[0,0] for i in range(m)] for j in range(n)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
dq = deque([[0,0,0]])
visit[0][0][0] = 1
time = 0
while dq:
    a = dq.popleft()
    x,y,sword = a[0],a[1],a[2]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if graph[nx][ny] == 2 and visit[nx][ny][0] == 0:
                visit[nx][ny][0] = visit[x][y][0] + 1 
                visit[nx][ny][1] = visit[x][y][0] + 1
                dq.append([nx,ny,1])
            elif visit[nx][ny][1] == 0 and sword == 1:
                if nx >= x and ny >= y:
                    visit[nx][ny][1] = visit[x][y][1] + 1
                    dq.append([nx,ny,1])
            elif sword == 0 and graph[nx][ny] == 0 and visit[nx][ny][0] == 0:
                dq.append([nx,ny,0])
                visit[nx][ny][0] = visit[x][y][0] + 1
zero = visit[n-1][m-1][0]-1
one = visit[n-1][m-1][1]-1
if zero == -1:
    zero = t+1
if one == -1:
    one = t+1
result = min(zero,one)
if result > t:
    print("Fail")
else:
    print(result)