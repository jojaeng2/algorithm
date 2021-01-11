result = [1]*1000000
result[1] = 2
result[2] = 4
for i in range(3,1000000):
    result[i] = (result[i-1]+result[i-2]+result[i-3])%1000000009
t = int(input())
for i in range(t):
    num = int(input())
    print(result[num-1])
