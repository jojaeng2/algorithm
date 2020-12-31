import sys
n = int(sys.stdin.readline())
li = []
for i in range(n):
    li.append(int(input()))
li.sort(reverse=True)
result = 0
for i in range(n):
    result= max (result,li[i]*(i+1))
print(result)
