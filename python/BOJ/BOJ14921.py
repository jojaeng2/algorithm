import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
start, end = 0, n-1
sum = num[start] + num[end]
while start < end:
    if num[start] + num[end] == 0:
        sum = 0
        break
    elif num[start] + num[end] < 0:
        if abs(num[start] + num[end]) <= abs(sum):
            sum = num[start] + num[end]
        start += 1
    else:
        if abs(num[start] + num[end]) <= abs(sum):
            sum = num[start] + num[end]
        end -= 1
print(sum)
