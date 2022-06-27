import sys
input = sys.stdin.readline
n,m = map(int,input().split())
me = list(map(int,input().split()))
co = list(map(int,input().split()))
dp = [[0 for i in range(sum(co)+1)] for j in range(n+1)]
result = sum(co)
for i in range(1,n+1):
    memory = me[i-1]
    cost = co[i-1]
    for j in range(1,sum(co)+1):
        if j < cost:
            dp[i][j] = dp[i-1][j]
        else:
            dp[i][j] = max(memory+dp[i-1][j-cost],dp[i-1][j])
        if dp[i][j] >= m:
            result = min(result,j)
if m != 0:
    print(result)
else:
    print(0)
