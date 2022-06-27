import sys
while True:
    num = list(map(int,input()))
    if num[0] == 0:
        break
    n = len(num)
    result = True
    for i in range(n//2):
        if num[i] != num[len(num)-1-i]:
            result = False
            break
    if result == True:
        print("yes")
    else:
        print("no")
