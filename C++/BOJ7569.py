import sys
n = int(input())
li =[]
result = 0
def dfs(cnt):
    global result
    if cnt == n:
        result += 1
        return
    for i in range(n):
        bl = True
        for j in range(cnt):
            if li[j] == i or abs(li[j]-i) == cnt - j:
                bl = False
                break
        if bl == True:
            li.append(i)
            dfs(cnt+1)
            li.pop()
dfs(0)
print(result)