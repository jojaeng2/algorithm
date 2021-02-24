from collections import deque
import sys
input = sys.stdin.readline
t = int(input())
dx = [-2,-2,-1,-1,1,1,2,2]
dy = [-1,1,-2,2,-2,2,-1,1]

for i in range(t):
    dq = deque([])
    n = int(input())
    bfs = [[0 for j in range(n)]for p in range(n)]
    a,b = map(int,input().split())
    c,d = map(int,input().split())
    dq.append([a,b])
    bfs[a][b] = 1
    while dq:
        e = dq.popleft()
        x,y = e[0],e[1]
        for j in range(8):
            nx = x + dx[j]
            ny = y + dy[j]
            if 0 <= nx < n and 0 <= ny < n:
                if bfs[nx][ny] == 0:
                    bfs[nx][ny] = bfs[x][y] + 1
                    dq.append([nx,ny])
    print(bfs[c][d]-1)