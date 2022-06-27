import sys
input = sys.stdin.readline
n = int(input())
num = []
x = 0
for i in range(n):
    a,b = map(int,input().split())
    x += b
    num.append([a,b])
y = 0
num.sort()
if x % 2 == 0:
    pass
else:
    x += 1
for i in range(n):
    y += num[i][1]
    if y >= x//2:
        print(num[i][0])
        break
