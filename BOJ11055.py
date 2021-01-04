n =int(input())
li = list(map(int,input().split()))
result = li
for i in range(n):
    for k in range(i):
        if li[i] > li[k]:
            result[i] = max(result[i], result[k]+li[i])
print(max(result))
