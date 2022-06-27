from collections import deque
dx = [-1,1,0,0,-1,1]
dy = [0,0,1,-1,0,0]

def bfs():
    while dq:
        a = dq.popleft()
        z,x,y = a[0],a[1],a[2]
        for i in range(6):
            if i >= 4:
                nz = z + dx[i]
                nx = x
                ny = y
            else:
                nz = z
                nx = x + dx[i]
                ny = y + dy[i]
            if 0 <= nz < l and 0 <= nx < r and 0 <= ny < c:
                if graph[nz][nx][ny] != "#" and visit[nz][nx][ny] == 0:
                    visit[nz][nx][ny] = visit[z][x][y] + 1
                    dq.append([nz,nx,ny])

while True:
    l,r,c = map(int,input().split())
    if l == 0 or r == 0 or c == 0:
        break
    graph = [[]for i in range(l)]
    for i in range(l):
        for j in range(r):
            graph[i].append(list(map(str,input())))
        input()
    visit = [[[0 for p in range(c)] for j in range(r)]for i in range(l)]
    dq = deque([])
    for i in range(l):
        for j in range(r):
            for p in range(c):
                if graph[i][j][p] == "S":
                    dq.append([i,j,p])
                    visit[i][j][p] = 1
                elif graph[i][j][p] == "E":
                    end = [i,j,p]
    bfs()
    az,ax,ay = end[0],end[1],end[2]
    if visit[az][ax][ay] == 0:
        print('Trapped!')
    else:
        print('Escaped in %d minute(s).' %(visit[az][ax][ay]-1))