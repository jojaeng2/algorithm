import sys
input = sys.stdin.readline
li = [0] * 10001
n = int(input())
for i in range(n):
    li[int(input())] += 1
for i in range(10000):
    if li[i] != 0:
        for j in range(li[i]):
            print(i)
