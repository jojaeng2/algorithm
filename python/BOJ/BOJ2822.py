num = []
for i in range(8):
    num.append(int(input()))
li = []
for i in num:
    li.append(i)
li.sort()
result = []
sum = 0
for i in range(5):
    print(li)
    print(num)
    a = li.pop()
    sum += a
    result.append(num.index(a)+1)
print(sum)
for i in result:
    print(i,end=' ')