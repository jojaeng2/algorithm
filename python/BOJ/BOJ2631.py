import sys
input = sys.stdin.readline
n = int(input())
num = []
for i in range(n):
    num.append(int(input()))
li = [0 for i in range(n)]
for i in range(n):
    for j in  range(i-1,-1,-1):
        if num[i] > num[j]:
            li[i] = max(li[i],li[j])
    li[i] += 1
print(li)
print(n-max(li))