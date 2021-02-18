h,w = map(int,input().split())
li = list(map(int,input().split()))
sum = 0
for i in range(1,w-1):
    left = max(li[:i])
    right = max(li[i+1:])
    result = min(left,right)-li[i]
    if result >= 0:
        sum += result
print(sum)