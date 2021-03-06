from collections import deque
n = int(input())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input())))
visit = []
for i in range(n):
    visit.append([0]*n)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
result = []
dq = deque([])
for i in range(n):
    for j in range(n):
        if bfs[i][j] == 1 and visit[i][j] == 0:
            dq.append([i,j])
            sum = 1
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if bfs[nx][ny] == 1 and visit[nx][ny] == 0:
                            sum += 1
                            dq.append([nx,ny])
                            visit[nx][ny] = 1
            result.append(sum)
print(len(result))
result.sort()
for i in result:
    if i == 1:
        print(i)
    else:
        print(i-1)
