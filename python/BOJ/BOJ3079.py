import sys
input = sys.stdin.readline
n,m = map(int,input().split())
li = []
for i in range(n):
    li.append(int(input()))
start = 1
end = max(li)*m
result = 0
while start <= end:
    total = 0
    mid = (start + end) // 2
    for i in li:
        total += mid // i
    if total < m:
        start = mid + 1
    else:
        end = mid -1
        result = mid
print(result)