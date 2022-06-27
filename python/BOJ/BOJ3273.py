import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
m = int(input())
num.sort()
start,end = 0,n-1
result = 0
while start < end:
    if num[start] + num[end] == m:
        result += 1
        start += 1
    elif num[start] + num[end] > m:
        end -= 1
    else:
        start += 1
print(result)        
