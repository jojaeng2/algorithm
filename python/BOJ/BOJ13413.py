t = int(input())
for i in range(t):
    n = int(input())
    li = list(map(str,input()))
    dat = list(map(str,input()))
    result = 0
    result += abs(li.count('W')-dat.count('W'))
    sum = 0
    for j in range(n):
        if li[j] != dat[j]:
            sum += 1
    sum -= result
    sum //= 2
    result += sum
    print(result)