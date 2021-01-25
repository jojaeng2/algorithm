n = int(input())
li = []
for i in range(n):
    li.append(list(input().split()))
li.sort(key = lambda x:(-int(x[1]),int(x[2]),-int(x[3]),x[0]))
for i in range(len(li)):
    print(li[i][0])
