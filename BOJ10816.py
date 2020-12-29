from collections import Counter
import sys
n = int(sys.stdin.readline())
li = list(map(int,sys.stdin.readline().split()))
m = int(sys.stdin.readline())
data = list(map(int,sys.stdin.readline().split()))
li = Counter(li)
for i in range(m):
    print(li[data[i]], end=" ")
