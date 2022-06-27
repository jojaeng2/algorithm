import sys
input = sys.stdin.readline
n,m,k = map(int,input().split())
feed = []
for i in range(n):
    feed.append(list(map(int,input().split())))
soil = [[5 for i in range(n)]for j in range(n)]
tree = [[[] for i in range(n)]for j in range(n)]
for i in range(m):
    x,y,z = map(int,input().split())
    x -= 1
    y -= 1
    tree[x][y].append(z)
dx = [0,0,-1,1,1,1,-1,-1]
dy = [-1,1,0,0,1,-1,1,-1]
for i in range(k):
    for j in range(n):
        for p in range(n):
            if len(tree[j][p]) != 0:
                cnt = 0
                li = tree[j][p]
                li.sort()
                for q in range(len(li)):
                    if li[q] <= soil[j][p]:
                        cnt += 1
                        soil[j][p] -= li[q]
                        li[q] += 1
                    else:
                        break
                for q in range(len(li)-cnt):
                    soil[j][p] += li.pop()//2
    for j in range(n):
        for p in range(n):
            if len(tree[j][p]) != 0:
                li = tree[j][p]
                for q in li:
                    if q % 5 == 0:
                        for o in range(8):
                            nx = j + dx[o]
                            ny = p + dy[o]
                            if 0 <= nx < n and 0 <= ny < n:
                                tree[nx][ny].append(1)
            soil[j][p] += feed[j][p]
result = 0
for i in range(n):
    for j in range(n):
        result += len(tree[i][j])
print(result)