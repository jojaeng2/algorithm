import sys
sys.setrecursionlimit(10**9)
input = sys.stdin.readline
n,m = map(int,input().split())
alpha = list(map(str,input().rstrip().split()))
alpha.sort()
visit = [False] * m
li = []
dat = ["a","e","i","o","u"]

def dfs(cnt):
    if cnt == n:
        mo,ja = 0,0
        for i in li:
            if i in dat:
                mo += 1
            else:
                ja += 1
        if mo >= 1 and ja >= 2:
            print(''.join(map(str,li)))
        return
    for i in range(m):
        if visit[i] == True:
            continue
        visit[i] = True
        li.append(alpha[i])
        dfs(cnt+1)
        li.pop()
        for j in range(i+1,m):
            visit[j] = False
dfs(0)