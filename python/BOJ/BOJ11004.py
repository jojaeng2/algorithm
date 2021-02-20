import sys
n,m = map(int,sys.stdin.readline().split())
num = list(map(int,sys.stdin.readline().split()))
num.sort()
print(num[m-1])
