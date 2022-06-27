n,m = map(int,input().split())
li1 = []
li2 = []
for i in range(n):
    li1.append(str(input()))
for i in range(m):
    li2.append(str(input()))
result = list(set(li1)&set(li2))
result.sort()
print(len(result))
for i in result:
    print(i)
