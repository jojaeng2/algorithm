n,m = map(int,input().split())
li = []
for i in range(n):
    li.append([1])
for i in range(2,m+1):
    li[0].append(i)
for i in range(1,n):
    for k in range(1,m):
        if k == 1:
            li[i].append((i+1)+1)
        else:
            li[i].append((li[i-1][k]+li[i][k-1])%1000000000)
print(li[n-1][-1])
print(li)
