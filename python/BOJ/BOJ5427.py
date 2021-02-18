import sys
from collections import deque
input = sys.stdin.readline
t = int(input())
for i in range(t):
    w,h = map(int,input().split())
    bfs = []
    visit = []
    fire = []
    for j in range(h):
        bfs.append(list(map(str,input())))
        visit.append([0]*w)
        fire.append([0]*w)
    dq = deque([])
    dp = deque([])
    dx = [0,0,-1,1]
    dy = [-1,1,0,0]
    for j in range(h):
        for p in range(w):
            if bfs[j][p] == "*":
                dq.append([j,p])
                fire[j][p] = 1
            if bfs[j][p] == "@":
                dp.append([j,p])
                visit[j][p] = 1
    while dq:
        a = dq.popleft()
        x,y = a[0],a[1]
        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]
            if 0 <= nx < h and 0 <= ny < w:
                if bfs[nx][ny] == "." and fire[nx][ny] == 0:
                    fire[nx][ny] = fire[x][y] + 1
                    dq.append([nx,ny])
    for j in range(h):
        for p in range(w):
            if fire[j][p] == 0:
                fire[j][p] = -1
    result = []
    while dp:
        a = dp.popleft()
        x,y = a[0],a[1]
        for j in range(4):
            nx = x + dx[j]
            ny = y + dy[j]
            if 0 <= nx < h and 0 <= ny < w:
                if bfs[nx][ny] == "." and visit[nx][ny] == 0:
                    if visit[x][y] + 1 < fire[nx][ny] or fire[nx][ny] == -1:
                        dp.append([nx,ny])
                        visit[nx][ny] = visit[x][y] + 1
            else:
                if visit[x][y] != 0:
                    result.append(visit[x][y])                
    if len(result) == 0:
        print("IMPOSSIBLE")
    else:
        print(min(result))
    