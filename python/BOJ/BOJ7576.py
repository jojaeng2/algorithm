from collections import deque
m,n = map(int,input().split())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input().split())))
visit = []
for i in range(n):
    visit.append([0]*m)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
for i in range(n):
    for j in range(m):
        if bfs[i][j] == 1:
            dq.append([i,j])
            visit[i][j] = 1
        elif bfs[i][j] == -1:
            visit[i][j] = -1
while dq:
    a = dq.popleft()
    x,y = a[1],a[0]
    for i in range(4):
        nx = x + dx[i]
        ny = y + dy[i]
        if 0 <= nx < m and 0 <= ny < n:
            if bfs[ny][nx] == 0 and visit[ny][nx] == 0:
                dq.append([ny,nx])
                visit[ny][nx] = visit[y][x] + 1
data = True
result = 0
for i in visit:
    if 0 in i:
        data = False
        break
    else:
        result = max(result,max(i))
if data == False:
    print(-1)
else:
    print(result-1)
