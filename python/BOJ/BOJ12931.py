n = int(input())
num = list(map(int,input().split()))
result = 0
while True:
    for i in range(n):
        if num[i] % 2 == 1:
            result += 1
            num[i] -= 1
    bl = True
    for i in range(n):
        if num[i] != 0:
            bl = False
            break
    if bl == True:
        break
    else:
        result += 1
        for i in range(n):
            num[i] //= 2
print(result)