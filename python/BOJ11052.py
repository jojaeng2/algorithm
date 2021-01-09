n = int(input())
result = [0]*(n+1)
li = [0]
li += list(map(int,input().split()))
print(li)
result[1] = li[1]
for i in range(2,n+1):
    for j in range(1,i+1):
        if result[i] < result[i-j] + li[j]:
            result[i] = result[i-j] + li[j]
print(result)
print(result[-1])
