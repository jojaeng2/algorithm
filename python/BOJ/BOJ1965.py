n = int(input())
num = list(map(int,input().split()))
dp = [1 for i in range(n)]
for i in range(1,n):
    result = 1
    for j in range(i):
        if num[i] > num[j]:
            result = max(result,dp[j]+1)
    dp[i] = result
print(max(dp))