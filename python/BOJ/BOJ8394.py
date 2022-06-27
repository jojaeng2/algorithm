dp = [1 for i in range(10000001)]
for i in range(2,10000001):
    dp[i] = (dp[i-1]+dp[i-2])%10
n = int(input())
print(dp[n])