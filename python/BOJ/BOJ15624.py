n = int(input())
num = [1]*1000001
num[0] = 0
for i in range(3,1000001):
    num[i] = (num[i-1]+num[i-2]) % 1000000007
print(num[n])