from collections import deque
n,m = map(int,input().split())
bfs = []
visit = [[0 for i in range(m)] for j in range(n)]
for i in range(n):
    bfs.append(list(map(int,input())))
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
for j in range(m):
    if bfs[0][j] == 0:
        dq.append([0,j])
        visit[0][j] = 1
        while dq:
            a = dq.popleft()
            x,y = a[0],a[1]
            for i in range(4):
                nx = x + dx[i]
                ny = y + dy[i]
                if 0 <= nx < n and 0 <= ny < m:
                    if bfs[nx][ny] == 0 and visit[nx][ny] == 0:
                        visit[nx][ny] = 1
                        dq.append([nx,ny])
print(bfs)
print(visit)
if 1 in visit[n-1]:
    print('YES')
else:
    print('NO')