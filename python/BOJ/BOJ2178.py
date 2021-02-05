from collections import deque
n,m = map(int,input().split())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input())))
visit = []
for i in range(n):
    visit.append([0]*m)
dq = deque([[0,0]])
dx = [0,0,-1,1]
dy = [-1,1,0,0]
while dq:
    a = dq.popleft()
    x,y = a[0],a[1]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < n and 0 <= ny < m:
            if bfs[nx][ny] == 1 and visit[nx][ny] == 0:
                visit[nx][ny] = visit[x][y] + 1
                dq.append([nx,ny])
print(visit[n-1][m-1]+1)
