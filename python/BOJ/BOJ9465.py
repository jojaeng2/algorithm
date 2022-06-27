n = int(input())

for i in range(n):
    li = []
    m = int(input())
    for k in range(2):
        li.append(list(map(int,input().split())))
    li[0][1] += li[1][0]
    li[1][1] += li[0][0]
    for i in range(2,m):
        li[0][i] = max(li[1][i-2]+li[0][i],li[1][i-1]+li[0][i])
        li[1][i] = max(li[0][i-2]+li[1][i],li[0][i-1]+li[1][i])
    print(max(li[0][-1],li[1][-1]))
