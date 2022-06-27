from collections import deque
n = int(input())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input().split())))
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
log = []
size = 2
eat = 0
result = 0
while True:
    visit = [[0 for i in range(n)]for j in range(n)]
    for i in range(n):
        for j in range(n):
            if bfs[i][j] == 9:
                dq.append([i,j])
                c,d = i,j
                visit[i][j] = 1
    dat = []
    if eat == size:
        size += 1
        eat = 0
    while dq:
        a = dq.popleft()
        x,y = a[0],a[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < n and 0 <= ny < n:
                if bfs[nx][ny] <= size and visit[nx][ny] == 0:
                    if bfs[nx][ny] > 0 and bfs[nx][ny] != size:
                        visit[nx][ny] = visit[x][y] + 1
                        dat.append([visit[nx][ny],nx,ny])
                    elif bfs[nx][ny] == 0 or bfs[nx][ny] == size:
                        dq.append([nx,ny])
                        visit[nx][ny] = visit[x][y] + 1
    dat.sort(key=lambda x:(x[0],x[1],x[2])) 
    if len(dat) == 0:
        break
    else:
        bfs[c][d] = 0
        bfs[dat[0][1]][dat[0][2]] = 9
        eat += 1
    result += (dat[0][0] - 1)
print(result)