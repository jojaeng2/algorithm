import sys
input = sys.stdin.readline
n = int(input())
dic = {}
for i in range(n):
    a,b = map(str,input().split())
    if a == "add":
        if b not in dic:
            dic.add(b)
    elif a == "remove":
        if b in dic:
            dic.remove(b)
    elif a == "check":
        if b in dic:
            print(1)
        else:
            print(0)
    elif a == "toggle":
        if b in dic:
            dic.remove(b)
        else:
            dic.add(b)
    elif a == "all":
        dic = {"1","2","3","4","5","6","7","8","9","10","11","12","13","14","15","16","17","18","19","20"}
    else:
        dic = {}
