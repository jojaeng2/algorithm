import sys
n = int(input())
b = [1]*n
a = list(map(int,sys.stdin.readline().split()))

for i in range(1,n):
    data = [0]
    result = []
    for k in range(i):
        if a[i] > a[k]:
            data.append(k)
    for p in data:
        result.append(b[p])
    b[i]=max(result)+1
print(max(b))
