import sys
n = int(input())
li = []
for i in range(n):
    li.append(list(map(int,sys.stdin.readline().split())))
data = []
li.sort(key = lambda x:x[0])
for i in range(n):
    data.append(li[i][1])
result = [1]*n
for i in range(1,n):
    for k in range(i):
        if data[i] > data[k]:
            result[i] = max(result[i],result[k]+1)
print(n-max(result))
