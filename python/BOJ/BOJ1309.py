n = int(input())
li = [3]*100001
li[2] = 7
for i in range(3,100001):
    li[i] = (li[i-1]*2) + li[i-2]
print(li[n])