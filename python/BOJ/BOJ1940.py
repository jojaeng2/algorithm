import sys
input = sys.stdin.readline
n = int(input())
m = int(input())
num = list(map(int,input().split()))
num.sort()
count,left,right = 0,0,n-1
while left < right:
    if num[left] + num[right] == m:
        count += 1
        left += 1
        right -= 1
    elif num[left] + num[right] < m:
        left += 1
    else:
        right -= 1
print(count)
