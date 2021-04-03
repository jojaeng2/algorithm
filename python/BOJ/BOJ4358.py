import sys
input = sys.stdin.readline
dic = {}
li = []
cnt = 0
while True:
    tree = input().rstrip()
    if tree == "":
        break
    cnt += 1
    if tree not in dic:
        dic[tree] = 1
        li.append(tree)
    else:
        dic[tree] += 1
    
li.sort()
for i in li:
    print(i,"%.4f" %((dic[i]/cnt)*100))