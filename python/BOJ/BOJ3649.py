import sys
input = sys.stdin.readline
while True:
    t = input()
    if t == "":
        break
    t = int(t)*10000000
    n = int(input())
    li = []
    for i in range(n):
        li.append(int(input()))
    bl = False
    li.sort()
    for i in range(n):
        start,end = i+1,n-1
        while start <= end:
            mid = (start+end)//2
            if li[i] + li[mid] == t:
                print("yes",li[i],li[mid])
                bl = True
                break
            elif li[i] + li[mid] < t:
                start = mid + 1
            else:
                end = mid - 1
        if bl == True:
            break
    if bl == False:
        print('danger')