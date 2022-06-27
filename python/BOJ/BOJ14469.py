n = int(input())
li = []
for i in range(n):
    enter,out = map(int,input().split())
    li.append([enter,out])
li.sort(key=lambda x:(x[0],x[1]))
li[0][1] += li[0][0]
for i in range(1,n):
    if li[i][0] >= li[i-1][1]:
        li[i][1] += li[i][0]
    else:
        li[i][0] = li[i-1][1]
        li[i][1] += li[i][0]
print(li)
print(li[n-1][1])