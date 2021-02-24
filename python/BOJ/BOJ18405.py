import sys
input = sys.stdin.readline
n,k = map(int,input().split())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input().split())))
s,b,c = map(int,input().split())
dx = [0,0,-1,1]
dy = [-1,1,0,0]

for q in range(s):
    li = []
    for p in range(n):
        a = []
        for u in range(n):
            a.append(bfs[p][u])
        li.append(a)
    print(bfs)
    print(li)
    for i in range(n):
        for j in range(n):
            if bfs[i][j] == 0:
                dat = []
                for p in range(4):
                    nx = i + dx[p]
                    ny = j + dy[p]
                    if 0 <= nx < n and 0 <= ny < n:
                        if li[nx][ny] != 0:
                            dat.append(li[nx][ny])
                print(q,dat)            
                if len(dat) > 0:
                    bfs[i][j] = min(dat)
print(bfs[b-1][c-1])
print(bfs)