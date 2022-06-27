n,m = map(int,input().split())
dp = []
for i in range(n):
    dp.append(list(map(int,input())))
result = 0
for i in range(n):
    for j in range(m):
        if i > 0 and j > 0:
            if dp[i][j] == 1:
                if dp[i-1][j-1] != 0 and dp[i-1][j] != 0 and dp[i][j-1] != 0:
                    dp[i][j] = min(dp[i-1][j-1],dp[i-1][j],dp[i][j-1]) + 1
                    result = max(result,dp[i][j])
                else:
                    result = 1
        else:
            if dp[i][j] == 1:
                result = 1    
print(result**2)