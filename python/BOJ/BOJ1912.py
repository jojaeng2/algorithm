n = int(input())
li = list(map(int,input().split()))
result = [li[0]]*n
for i in range(n-1):
    result[i+1] = max(result[i]+li[i+1],li[i+1])
print(max(result))
