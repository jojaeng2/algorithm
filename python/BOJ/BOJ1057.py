n,a,b = map(int,input().split())
li = [a,b]
li.sort()
a,b = li[0],li[1]
result = 0
print(a,b)
while True:
    result += 1
    if a+1 == b and b%2 == 0:
        print(result)
        break
    else:
        if a % 2 != 0:
            a += 1
        if b % 2 != 0:
            b += 1
        a //= 2
        b //= 2