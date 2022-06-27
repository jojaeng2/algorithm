from collections import deque
n,m = map(int,input().split())
li = []
for i in range(n):
    li.append(list(map(int,input().split())))
dq = deque([])
dx = [0,0,-1,1]
dy = [-1,1,0,0]
result = 0
while True:
    sum = 0
    visit=[[0 for p in range(m)] for q in range(n)]
    map = []
    for i in range(n):
        a = []
        for j in range(m):
            a.append(li[i][j])
        map.append(a)
    for i in range(n):
        for j in range(m):
            if li[i][j] > 0 and visit[i][j] == 0:
                sum += 1
                visit[i][j] = 1
                dq.append([i,j])
                while dq:
                    a = dq.popleft()
                    x,y = a[0],a[1]
                    for p in range(4):
                        nx = x + dx[p]
                        ny = y + dy[p]
                        if 0 <= nx < n and 0 <= ny < m:
                            if li[nx][ny] > 0 and visit[nx][ny] == 0:
                                dq.append([nx,ny])
                                visit[nx][ny] = 1
    if sum == 0:
        break
    elif sum >= 2:
        break
    else:
        result += 1
        for i in range(n):
            for j in range(m):
                if li[i][j] > 0:
                    dq.append([i,j])
                    while dq:
                        a = dq.popleft()
                        x,y = a[0],a[1]
                        for p in range(4):
                            nx = x + dx[p]
                            ny = y + dy[p]
                            if 0 <= nx < n and 0 <= ny < m:
                                if map[nx][ny] <= 0:
                                    li[x][y] -= 1
if sum == 0:
    print(0)
else:
    print(result)
