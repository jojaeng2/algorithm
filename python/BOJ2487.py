n = int(input())
li = []
for i in range(n):
    li.append(int(input()))
li.reverse()
sum = 0
for i in range(1,n):
    if li[i] >= li[i-1]:
        sum += li[i]-li[i-1]+1
        li[i] = li[i-1]-1
print(sum)
