import sys
input = sys.stdin.readline
n,m = map(int,input().split())
li = []
for i in range(n):
    li.append(int(input()))
li.sort()
start, end = 0,0
result = []
while start <= end and end < n:
        if li[end] - li[start] >= m:
            result.append(li[end]-li[start])
            start += 1
        else:
            end += 1
print(min(result))
