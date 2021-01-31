n = int(input())
li = list(map(int,input().split()))
m = int(input())
li.sort()
left,right = 0,li[-1]
while left <= right:
    mid = (left+right) // 2
    sum = 0
    for i in li:
        if i <= mid:
            sum += i
        else:
            sum += mid
    if sum <= m:
        left = mid + 1
    else:
        right = mid - 1
print(right)
