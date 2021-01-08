from collections import Counter
n = int(input())
li = []
for i in range(n):
    li.append(str(input()))
li.sort()
li = list(Counter(li).most_common(1))

print(li[0][0])
