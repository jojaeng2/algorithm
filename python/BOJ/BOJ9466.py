import sys
sys.setrecursionlimit(200000)
input = sys.stdin.readline
t = int(input())
def dfs(i):
    global cnt
    visit[i] = True
    result.append(i)
    if visit[graph[i]] == False:
        return dfs(graph[i])
    else:
        temp = 0
        print(result,i)
        for p in range(len(result)):
            if result[p] != graph[i]:
                temp += 1
            else:
                cnt += temp
                return
        cnt += len(result)
        return
for i in range(t):
    n = int(input())
    graph = [0] + list(map(int,input().split()))
    cnt = 0
    visit = [False] * (n+1)
    for j in range(1,n+1):
        result = []
        if visit[j] == False:
            dfs(j)
    print(cnt)