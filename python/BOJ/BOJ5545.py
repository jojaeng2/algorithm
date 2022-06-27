n = int(input())
br,to = map(int,input().split())
a = int(input())
li = []
for i in range(n):
    li.append(int(input()))
li.sort()
result = a//br
for i in range(n):
    a += li.pop()
    br += to
    result = max(result,a//br)
print(result)