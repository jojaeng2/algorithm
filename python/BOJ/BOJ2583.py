import sys
from collections import deque
input = sys.stdin.readline
m,n,k = map(int,input().split())
bfs = []
visit = []
for i in range(m):
    bfs.append([1]*n)
    visit.append([0]*n)
dx = [0,0,-1,1]
dy = [-1,1,0,0]
for i in range(k):
    a,b,c,d = map(int,input().split())
    for j in range(b,d):
        for p in range(a,c):
            bfs[j][p] = 0
dq = deque([])
result = 0
answer = []
for i in range(m):
    for j in range(n):
        if bfs[i][j] == 1 and visit[i][j] == 0:
            result += 1
            sum = 1
            visit[i][j] = 1
            dq.append([i,j])
            while dq:
                a = dq.popleft()
                x,y = a[0],a[1]
                for p in range(4):
                    nx = x + dx[p]
                    ny = y + dy[p]
                    if 0 <= nx < m and 0 <= ny < n:
                        if bfs[nx][ny] == 1 and visit[nx][ny] == 0:
                            dq.append([nx,ny])
                            sum += 1
                            visit[nx][ny] = 1
            answer.append(sum)
answer.sort()
print(result)
for i in answer:
    print(i,end=" ")            
