import sys
input = sys.stdin.readline
n,m = map(int,input().split())
graph = []
x,y,d = map(int,input().split())
for i in range(n):
    graph.append(list(map(int,input().split())))
dx = [-1,0,1,0]
dy = [0,1,0,-1]
result = 0
graph[x][y] = 2
exitwhile = False
while exitwhile == False:
    bl = False
    while bl == False:
        for i in range(4):
            d -= 1
            if d < 0:
                d += 4
            nx = x + dx[d]
            ny = y + dy[d]
            if graph[nx][ny] == 0:
                x = nx
                y = ny
                result += 1
                graph[x][y] = 2
                bl = True
                break
        if bl == False:
            log = d - 2
            if log < 0:
                log += 4
            nx = x + dx[log]
            ny = y + dy[log]
            if graph[nx][ny] == 1:
                exitwhile = True
                break
            else:
                x = nx
                y = ny
print(result+1)