n,t = map(int,input().split())
li = [[0,0]]
for i in range(n):
    li.append(list(map(int,input().split())))
data = [[0 for i in range(t+1)] for j in range(n+1)]
for i in range(1,n+1):
    time,score = li[i][0],li[i][1]
    for j in range(1,t+1):
        if j < time:
            data[i][j] = data[i-1][j]
        else:
            data[i][j] = max(score + data[i-1][j-time],data[i-1][j])
print(data[n][t])
