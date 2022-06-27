n = int(input())
bfs = []
for i in range(n):
    bfs.append(list(map(int,input().split())))
visit = [[0 for i in range(n)]for j in range(n)]
visit[0][0] = 1
for i in range(n):
    for j in range(n):
        if i == n-1 and j == n-1:
            break
        val = bfs[i][j]
        if i + val < n:
            visit[i+val][j] += visit[i][j]
        if j + val < n:
            visit[i][j+val] += visit[i][j]
        print(1)
print(visit)