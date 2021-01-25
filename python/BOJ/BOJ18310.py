n = int(input())
li = list(map(int,input().split()))
li.sort()
result = ((li[-1]+li[0])//2)
data = []
for i in range(n):
    data.append(abs(li[i]-result))
print(li[data.index(min(data))])
