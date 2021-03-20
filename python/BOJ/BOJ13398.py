import sys
input = sys.stdin.readline
n = int(input())
num = list(map(int,input().split()))
a = [num[0]]
b = [num[0]]
for i in range(1,n):
    x = a[-1]
    y = b[-1]
    a.append(max(num[i],x+num[i]))
    b.append(max(x,y+num[i]))
print(a)
print(b)
result = max(max(a),max(b))
print(result)