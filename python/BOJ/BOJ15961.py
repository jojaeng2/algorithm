import sys
input = sys.stdin.readline
n,d,k,c = map(int,input().split())
result = []
for i in range(n):
    result.append(int(input()))
dic = {}
for i in range(k):
    if result[i] in dic:
        dic[result[i]] += 1
    else:
        dic[result[i]] = 1
if c in dic:
    data = len(dic)
else:
    data = len(dic) + 1
start,end = 0,k-1
while start < n:
    end += 1
    if end == n:
        end = 0
    if result[end] in dic:
        dic[result[end]] += 1
    else:
        dic[result[end]] = 1
    if dic[result[start]] == 1:
        del dic[result[start]]
    else:
        dic[result[start]] -= 1
    start += 1
    if c in dic:
        data = max(len(dic),data)
    else:
        data = max(len(dic)+1,data)
print(data)
