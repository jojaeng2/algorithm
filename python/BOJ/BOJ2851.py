num = []
for i in range(10):
    num.append(int(input()))
result = 0
for i in range(10):
    if abs(100-result) >= abs(100-(result+num[i])):
        result += num[i]
    else:
        break
print(result)