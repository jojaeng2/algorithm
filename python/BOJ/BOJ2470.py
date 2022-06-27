import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
start,end = 0,n-1
num.sort()
result = [num[0],num[-1]]
while end > start:
    if abs(num[start] + num[end]) <= abs(result[0] + result[1]):
        result[0],result[1] = num[start],num[end]
        if num[start] + num[end] < 0:
            start += 1
        else:
            end -= 1
    else:
        if num[start] + num[end] < 0:
            start += 1
        else:
            end -= 1
print(result[0],result[1])
