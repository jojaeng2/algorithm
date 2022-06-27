from collections import deque
n,m = map(int,input().split())
bfs = []
data = []
for i in range(n):
    data.append([0]*m)
for i in range(n):
    bfs.append(list(map(int,input().split())))
dx = [0,0,-1,1]
dy = [1,-1,0,0]
sum = []
dq = deque([])
for i in range(n):
    for j in range(m):
        if bfs[i][j] == 1 and data[i][j] == 0:
            result = 1
            dq.append([i,j])
            data[i][j] = 1
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < m:
                        if data[nx][ny] == 0 and bfs[nx][ny] == 1:
                            dq.append([nx,ny])
                            result += 1
                            data[nx][ny] = 1
            sum.append(result)
print(len(sum))
if len(sum) == 0:
    print(0)
else:
    print(max(sum))
