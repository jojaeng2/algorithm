result = [1,3]
for i in range(2,1000):
    result.append(result[i-1]+result[i-2]*2)
num = int(input())
print(result[num-1]%10007)
