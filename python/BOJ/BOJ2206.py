from collections import deque
n,m = map(int,input().split())
graph = [[0 for i in range(m+1)]]
visit = [[[0,0] for i in range(m+1)] for j in range(n+1)]
dx = [-1,1,0,0]
dy = [0,0,-1,1]
dq = deque([[1,1,0]])
visit[1][1][0],visit[1][1][1] = 1,1
for i in range(n):
    graph.append([0]+list(map(int,input())))
while dq:
    a = dq.popleft()
    x,y,breaked = a[0],a[1],a[2]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 1 <= nx < n+1 and 1 <= ny < m+1:
            if graph[nx][ny] == 1 and visit[nx][ny][1] == 0 and breaked == 0:
                dq.append([nx,ny,1])
                visit[nx][ny][1] = visit[x][y][0] + 1
            elif graph[nx][ny] == 0 and visit[nx][ny][0] == 0 and breaked == 0:
                dq.append([nx,ny,0])
                visit[nx][ny][0] = visit[x][y][0] + 1
            elif graph[nx][ny] == 0 and visit[nx][ny][1] == 0 and breaked == 1:
                dq.append([nx,ny,1])
                visit[nx][ny][1] = visit[x][y][1] + 1

if visit[n][m][0] == 0 and visit[n][m][1] == 0:
    print(-1)
elif visit[n][m][0] == 0:
    print(visit[n][m][1])
elif visit[n][m][1] == 0:
    print(visit[n][m][0])
else:
    print(min(visit[n][m][0],visit[n][m][1]))
