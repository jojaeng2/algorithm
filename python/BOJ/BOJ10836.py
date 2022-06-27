import sys
input = sys.stdin.readline
n,m = map(int,input().split())
li = [[1 for i in range(n)]for j in range(n)]
visit = [0 for i in range(2*n-1)]
for i in range(m):
    zero,one,two = map(int,input().split())
    for j in range(zero,zero+one):
        visit[j] += 1
    for j in range(zero+one,2*n-1):
        visit[j] += 2
for i in range(n):
    li[i][0] += visit[n-i-1]
    for j in range(1,n):
        li[i][j] += visit[n+j-1]
for i in range(n):
    for j in range(n):
        print(li[i][j],end=" ")
    print("")