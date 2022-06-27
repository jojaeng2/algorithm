from collections import deque
import sys
input = sys.stdin.readline
dx = [-1,-1,0,1,1,1,0,-1]
dy = [0,1,1,1,0,-1,-1,-1]
n,m,k = map(int,input().split())
dq = deque([])
for i in range(m):
    dq.append(list(map(int,input().split())))

for m in range(k):
    visit = [[[0,0,[]] for i in range(n+1)]for j in range(n+1)]
    while dq:
        a = dq.popleft()
        x,y,weight,speed,direction = a[0],a[1],a[2],a[3],a[4]
        nx = (x + dx[direction] * speed) % n
        ny = (y + dy[direction] * speed) % n 
        if nx == 0:
            nx = n
        if ny == 0:
            ny = n
        visit[nx][ny][0] += weight
        visit[nx][ny][1] += speed
        visit[nx][ny][2].append(direction)
    for i in range(1,n+1):
        for j in range(1,n+1):
            if len(visit[i][j][2]) == 1:
                dq.append([i,j,visit[i][j][0],visit[i][j][1],visit[i][j][2][0]])
            else:
                if visit[i][j][0] // 5 > 0:
                    weight = visit[i][j][0] // 5
                    speed = visit[i][j][1] // len(visit[i][j][2])
                    flag = False
                    leader = visit[i][j][2][0] % 2
                    for p in range(len(visit[i][j][2])):
                        if visit[i][j][2][p] % 2 != leader:
                            flag = True
                            break
                    if flag != True:
                        for q in range(0,8,2):
                            dq.append([i,j,weight,speed,q])
                    else:
                        for q in range(1,8,2):
                            dq.append([i,j,weight,speed,q])
result = 0
for i in dq:
    result += i[2]
print(result)