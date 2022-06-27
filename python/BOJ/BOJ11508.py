n = int(input())
num = []
for i in range(n):
    num.append(int(input()))
num.sort(reverse=True)
sum = 0
for i in range(n):
    if (i+1) % 3 == 0:
        pass
    else:
        sum += num[i]
print(sum)