li = list(map(str,input()))
result = []
for i in range(len(li)):
    sum = ''
    for j in range(i,len(li)):
        sum += li[j]
    result.append(sum)
result.sort()
for i in result:
    print(i)
