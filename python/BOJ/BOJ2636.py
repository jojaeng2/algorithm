from collections import deque
h,w = map(int,input().split())
bfs = []
for i in range(h):
    bfs.append(list(map(int,input().split())))
dx = [0,0,-1,1]
dy = [-1,1,0,0]
dq = deque([])
time = 0
result = []
while True:
    sum = 0
    map = [] #li와 동일한 리스트를 만들기 위해서 map 리스트생성
    visit = [[0 for i in range(w)] for j in range(h)]
    for i in range(h):
        a = []
        for j in range(w):
            a.append(bfs[i][j])
        map.append(a)
    sum = 0
    dq.append([0,0])
    visit[0][0] = -1
    while dq:
        a = dq.popleft()
        x,y = a[0],a[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < h and 0 <= ny < w:
                if bfs[nx][ny] == 0 and visit[nx][ny] == 0:
                    visit[nx][ny] = -1
                    dq.append([nx,ny])
    for i in range(h):
        for j in range(w):
            if bfs[i][j] == 1:
                sum += 1
                for p in range(4):
                    x = i + dx[p]
                    y = j + dy[p]
                    if 0 <= x < h and 0 <= y < w:
                        if map[x][y] == 0 and visit[x][y] == -1:
                            bfs[i][j] = 0
                            visit[i][j] = -1
    time += 1
    result.append(sum)
    if sum == 0:
        break
print(time-1)
print(result[-2])