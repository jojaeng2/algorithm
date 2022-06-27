n = int(input())
paper = [[0]*100 for i in range(100)]
for i in range(n):
    x,y = map(int,input().split())
    for j in range(x,x+10):
        for p in range(y,y+10):
            paper[j][p] = 1
sum = 0
for i in paper:
    sum += i.count(1)
print(sum)