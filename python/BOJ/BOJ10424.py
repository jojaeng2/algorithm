import sys
input = sys.stdin.readline
n = int(input())
li = list(map(int,input().split()))
result = []
for i in range(n):
    result.append([li[i] - (i+1),li[i]])
result.sort(key=lambda x:x[1])
for i in result:
    print(i[0])
