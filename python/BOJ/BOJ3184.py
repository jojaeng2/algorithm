from collections import deque
n,m = map(int,input().split())
dq = deque([])
dx = [0,0,-1,1]
dy = [-1,1,0,0]
bfs = []
for i in range(n):
    bfs.append(list(map(str,input())))
visit = [[0 for i in range(m)] for j in range(n)]
a = 0
b = 0
for i in range(n):
    for j in range(m):
        if bfs[i][j] == "o":
            a += 1
        if bfs[i][j] == "v":
            b += 1
        if bfs[i][j] != "#":
            c,d = 0,0            
            if bfs[i][j] == "o":
                c = 1
            elif bfs[i][j] == "v":
                d = 1
            dq.append([i,j])
            visit[i][j] = 1
            while dq:
                e = dq.popleft()
                x,y = e[0],e[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < m:
                        if bfs[nx][ny] != "#" and visit[nx][ny] == 0:
                            if bfs[nx][ny] == "o":
                                c += 1
                            elif bfs[nx][ny] == "v":
                                d += 1
                            dq.append([nx,ny])
                            visit[nx][ny] = 1 
            if c > d:
                b -= d
            else:
                a -= c
print(a, b)                