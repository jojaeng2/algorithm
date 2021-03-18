from collections import deque
import sys
input = sys.stdin.readline
n,k,r = map(int,input().split())
graph = [[0 for i in range(n+1)]for j in range(n+1)]
bri = []
for i in range(r):
    bri.append(list(map(int,input().split())))
visit = [[0 for i in range(n+1)]for j in range(n+1)]
num = 0
for i in range(k):
    num += 1
    a,b = map(int,input().split())
    graph[a][b] = 1
result = 0
for i in range(num):
    result += i
dx = [-1,1,0,0]
dy = [0,0,-1,1]
dq = deque([])

def bfs(one):
    while dq:
        x,y = dq.popleft()
        for p in range(4):
            nx = x +dx[p]
            ny = y + dy[p]
            if 1 <= nx < n+1 and 1 <= ny < n+1:
                bl = True
                for q in range(r):
                    if bri[q][0] == x and bri[q][1] == y and bri[q][2] == nx and bri[q][3] == ny:
                        bl = False
                        break
                    elif bri[q][0] == nx and bri[q][1] == ny and bri[q][2] == x and bri[q][3] == y:
                        bl = False
                        break
                if bl == True and visit[nx][ny] == 0:
                    if graph[nx][ny] == 1:
                        one += 1
                    dq.append([nx,ny])
                    visit[nx][ny] = 1
    return one

for i in range(1,n+1):
    for j in range(1,n+1):
        if graph[i][j] == 1:
            one = 0
            dq.append([i,j])
            visit[i][j] = 1
            x = bfs(one)
            for p in range(x+1):
                result -= p
print(result)