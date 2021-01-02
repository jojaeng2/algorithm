n = list(map(str,input()))
result = 0
sum = 0
for i in range(len(n)):
    if n[i] == "(":
        result += 1
    else:
        result -= 1
        if n[i-1] == "(":
            sum += result
        else:
            sum += 1
print(sum)
