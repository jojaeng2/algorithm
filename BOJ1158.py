n,m = map(int,input().split())
li = []
for i in range(1,n+1):
    li.append(i)
result = []
num = m-1
for i in range(n):
    if num >= len(li):
        num = num%len(li)
    result.append(li[num])
    li.remove(li[num])
    num += m-1
print("<",end="")
for i in result:
    if i == result[-1]:
        print(i,end="")
    else:
        print(i,end=", ")
print(">")
