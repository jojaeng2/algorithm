li = list(map(int,input()))
result = [li[0]]
for i in range(1,len(li)):
    if li[i] != li[i-1]:
        result.append(li[i])
print(min(result.count(0),result.count(1)))
