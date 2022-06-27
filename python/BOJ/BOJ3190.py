import sys
from collections import deque
n = int(input())
bfs = []
for i in range(n):
    bfs.append([0]*n)
k = int(input())
for i in range(k):
    a,b = map(int,input().split())
    bfs[a-1][b-1] = "a"
time = []
t = int(input())
for i in range(t):
    time.append(list(map(str,input().split())))
time.reverse()
dx = [0,-1,0,1]
dy = [1,0,-1,0]
dq = deque([[0,0]])
move = 0
result = 0
bfs[0][0] = 1
while dq:
    print(bfs)
    print(result)
    print(move)
    result += 1
    a = dq.popleft()
    x,y = a[0],a[1]
    nx = x + dx[move]
    ny = y + dy[move]
    if 0 <= nx < n and 0 <= ny < n:
        if bfs[nx][ny] == 0 or bfs[nx][ny] == "a":
            dq.append([nx,ny])
            if bfs[nx][ny] == "a":
                bfs[nx][ny] = bfs[x][y] + 1
            else:
                for i in range(n):
                    for j in range(n):
                        if bfs[i][j] != 0 and bfs[i][j] != "a":
                            bfs[i][j] -= 1
                bfs[nx][ny] = bfs[x][y] + 1
        else:
            break
    else:
        break
    if len(time) > 0:
        if int(time[-1][0]) == result:
            change = time.pop()
            change = change[1]
            if change == "D":
                move -= 1
            else:
                move += 1
        

print(result)