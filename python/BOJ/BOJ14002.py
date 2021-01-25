n = int(input())
li = list(map(int,input().split()))
result = [1]*n
for i in range(n):
    for j in range(i):
        if li[i] > li[j]:
            result[i] = max(result[i], result[j]+1)
sum = max(result)
data = []
for i in range(n-1,-1,-1):
    if sum == result[i]:
        data.append(li[i])
        sum -= 1
data.reverse()
print(max(result))
for i in data:
    print(i,end=" ")
