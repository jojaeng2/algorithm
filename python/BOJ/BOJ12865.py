n,k = map(int,input().split())
li = [[0,0]]
for i in range(n):
    li.append(list(map(int,input().split())))
data = [[0 for i in range(k+1)] for j in range(n+1)]
for i in range(1,n+1):
    for j in range(1,k+1):
        weight = li[i][0]
        money = li[i][1]
        print(data)
        if j < weight:
            data[i][j] = data[i-1][j]
        else:
            data[i][j] = max(money+data[i-1][j-weight],data[i-1][j])
print(data[n][k])
