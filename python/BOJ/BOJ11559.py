from collections import deque
import sys
input = sys.stdin.readline
dx = [-1,1,0,0]
dy = [0,0,-1,1]
graph = []
for i in range(12):
    graph.append(list(map(str,input())))
def bfs(graph,dq,visit,num,dat):
    while dq:
        a = dq.popleft()
        x,y = a[0],a[1]
        for i in range(4):
            nx = x + dx[i]
            ny = y + dy[i]
            if 0 <= nx < 12 and 0 <= ny < 6:
                if graph[nx][ny] == graph[x][y] and visit[nx][ny] == 0:
                    visit[nx][ny] = 1
                    dq.append([nx,ny])
                    num += 1
                    dat.append([nx,ny])
    return num
def down(graph):
    for i in range(11,0,-1):
        for j in range(6):
            if graph[i][j] == ".":
                for p in range(i-1,-1,-1):
                    if graph[p][j] != ".":
                        graph[i][j] = graph[p][j]
                        graph[p][j] = "."
                        break
                        
result = 0
bre = 0
dq = deque([])
while True:
    boom = False
    bre = result
    visit = [[0 for i in range(6)]for j in range(12)]
    for i in range(12):
        for j in range(6):
            if graph[i][j] != "." and visit[i][j] == 0:
                dq.append([i,j])
                visit[i][j] = 1
                num = 1
                dat = [[i,j]]
                if bfs(graph,dq,visit,num,dat) >= 4:
                    boom = True
                    while dat:
                        a = dat.pop()
                        x,y = a[0],a[1]
                        graph[x][y] = "."
    if boom == True:
        result += 1
    else:
        print(result)
        break
    down(graph)
    