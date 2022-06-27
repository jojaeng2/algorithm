num = []
for i in range(1,101):
    num.append(i**2)
n = int(input())
m = int(input())
result = 0
ans = []
for i in num:
    if n <= i <= m:
        result += i
        ans.append(i)
    elif i > m:
        break
print(result)
print(ans[0])