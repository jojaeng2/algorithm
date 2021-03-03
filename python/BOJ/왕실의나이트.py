n = list(map(str,input()))
x,y = 0,0
li = [[0 for i in range(8)]for j in range(8)]
alpha = ['a','b','c','d','e','f','g','h']
for i in range(8):
    if alpha[i] == n[0]:
        y = i
x = int(n[1])-1
dx = [-2,-2,2,2,-1,-1,1,1]
dy = [-1,1,-1,1,-2,2,-2,2]
result = 0
for i in range(8):
    nx = x + dx[i]
    ny = y + dy[i]
    if 0 <= nx < 8 and 0 <= ny < 8:
        result += 1
print(result)