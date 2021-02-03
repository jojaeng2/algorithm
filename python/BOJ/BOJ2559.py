import sys
input = sys.stdin.readline
n,m = map(int,input().split())
num = list(map(int,input().split()))
start,end = 0,m-1
sum = 0
for i in range(m):
    sum += num[i]
data = sum
while end < n-1:
    end += 1
    data += num[end]
    data -= num[start]
    start += 1
    sum = max(data,sum)
print(sum)
