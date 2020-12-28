li = [2,3,5,7]
for i in range(10,246913):
    for k in range(2,497):
        if i > k:
            if i % k == 0:
                result = False
                break
            else:
                result = True
    if result == True:
        li.append(i)
while True:
    n = int(input())
    sum = 0
    if n == 0:
        break
    else:
        for i in range(len(li)):
            if li[i] > n and li[i] <= 2*n:
                sum += 1
            else:
                if li[i] > 2*n:
                    break
    print(sum)
