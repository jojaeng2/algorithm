n = int(input())
li = list(map(int,input().split()))
dq = list(map(int,input().split()))
data = [x for x in li]
sum = [x for x in dq]
for i in range(n):
    index = dq.index(max(dq))
    index2 = li.index(min(li))
    data[index] = li[index2]
    dq[index] = -1
    li[index2] = 101
result = 0
for i in range(n):
    result += data[i]*sum[i]
print(result)
