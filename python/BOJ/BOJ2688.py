t = int(input())
li = []
for i in range(64):
    li.append([1,1,1,1,1,1,1,1,1,1,10])
for i in range(1,64):
    result = li[i-1][-1]
    sum = result
    for p in range(11):
        if p == 0:
            li[i][p] = result
        elif p == 10:
            li[i][p] = sum
        else:
            li[i][p] = li[i][p-1]-li[i-1][p-1]
            sum += li[i][p]

for i in range(t):
    number = int(input())
    print(li[number-1][-1])
