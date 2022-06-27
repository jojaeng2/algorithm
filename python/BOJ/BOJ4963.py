import sys
from collections import deque
input = sys.stdin.readline
dq = deque([])
dx = [0,0,-1,1,1,1,-1,-1]
dy = [-1,1,0,0,1,-1,1,-1]
while True:
    w,h = map(int,input().split())
    if w == 0 and h == 0:
        break
    sum = 0
    bfs = []
    visit = []
    for i in range(h):
        visit.append([0]*w)
        bfs.append(list(map(int,input().split())))
    for i in range(h):
        for j in range(w):
            if bfs[i][j] == 1 and visit[i][j] == 0:
                visit[i][j] = 1
                sum += 1
                dq.append([i,j])
                while dq:
                    a = dq.popleft()
                    x,y = a[0],a[1]
                    for p in range(8):
                        nx = x + dx[p]
                        ny = y + dy[p]
                        if 0 <= nx < h and 0 <= ny < w:
                            if bfs[nx][ny] == 1 and visit[nx][ny] == 0:
                                visit[nx][ny] = 1
                                dq.append([nx,ny])
    print(sum)