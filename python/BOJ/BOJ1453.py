n = int(input())
li = [0 for i in range(101)]
num = list(map(int,input().split()))
num.reverse()
result = 0
while num:
    a = num.pop()
    if li[a] == 0:
        li[a] = 1
    else:
        result += 1
    
print(result)