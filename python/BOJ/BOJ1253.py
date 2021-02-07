import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
num.sort()
result = 0
for i in range(len(num)):
    start,end = 0,n-2
    li = num[:i]+num[i+1:]
    while end > start:
        if li[start] + li[end] == num[i]:
            result += 1
            break
        elif li[start] + li[end] > num[i]:
            end -= 1
        else:
            start += 1
print(result)
