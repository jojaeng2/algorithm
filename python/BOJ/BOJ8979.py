n,m = map(int,input().split())
li = []
for i in range(n):
    li.append(list(map(int,input().split())))
li.sort(key=lambda x:(-x[1],-x[2],-x[3]))
sum = 1
for i in range(len(li)):
    if li[i][0] == m:
        data = i
        break
for j in range(i):
    if li[j][1] > li[i][1]:
        sum += 1
    elif li[j][2] > li[i][2]:
        sum += 1
    elif li[j][3] > li[i][3]:
        sum += 1
print(sum)