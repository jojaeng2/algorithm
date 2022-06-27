n = int(input())
num = []
for i in range(n):
    num.append(int(input()))
num.sort(reverse=True)
result = 0
for i in range(n):
    if num[i]-i < 0:
        pass
    else:
        result += num[i] - i
print(result)
