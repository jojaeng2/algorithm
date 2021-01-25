n = int(input())
li = list(map(int,input().split()))
li.sort()
result = []
for i in li:
    if i not in result:
        result.append(i)
for i in result:
    print(i,end=" ")
