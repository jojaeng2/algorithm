li = list(map(int,input().split()))
result = 0
for i in li:
    result += (i**2)%10
print(result%10)    
