from collections import deque
r,c,n = map(int,input().split())
bfs = []
dx = [0,0,-1,1]
dy = [-1,1,0,0]
for i in range(r):
    bfs.append(list(map(str,input())))
time = 0
dq = deque([])
while time != n:
    time += 1
    if time % 2 == 1:
        while dq:
            a = dq.popleft()
            x,y = a[0],a[1]
            bfs[x][y] = "."
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < r and 0 <= ny < c:
                    bfs[nx][ny] = "."
    else:
        for i in range(r):
            for j in range(c):
                if bfs[i][j] == "O":
                    dq.append([i,j])
                else:
                    bfs[i][j] = "O"
for i in range(r):
    for j in range(c):
        print(bfs[i][j],end="")
    print("")