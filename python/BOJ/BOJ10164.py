n,m,k = map(int,input().split())
if k == 0:
    a = 0
    b = 1
else:
    a = k//m
    b = k % m
    if b == 0:
        a -=1
        b = m
print(a,b)
li = [[0]*m for i in range(n)]
if a == 0 or b == 1:
    for i in range(a+1):
        for j in range(b):
            li[i][j] = 1
else:
    for i in range(a+1):
        for j in range(b):
            if i == 0:
                li[i][j] = 1
            elif j == 0:
                li[i][j] = 1
            else:
                li[i][j] = li[i-1][j] + li[i][j-1]
for i in range(a,n):
    for j in range(b-1,m):
        if i == 0 and j == 0:
            pass
        elif i == 0:
            li[i][j] = li[i][j-1]
        elif j == 0:
            li[i][j] = li[i-1][j]
        else:
            li[i][j] = li[i-1][j] + li[i][j-1]
print(li[-1][-1])