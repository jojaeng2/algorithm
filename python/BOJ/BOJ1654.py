import sys
input = sys.stdin.readline
k,n = map(int,input().split())
li = []
for i in range(k):
    li.append(int(input()))
start = 1
end = max(li)
result = 0
while start <= end:
    total = 0
    mid = (start + end) // 2
    for i in li:
        total += i // mid
    if total < n:
        end = mid - 1
    else:
        result = mid
        start = mid + 1
print(result)