n = int(input())
for i in range(n):
    start = list(map(int,input().split()))
    circle = []
    result = 0
    t = int(input())
    for k in range(t):
        circle.append(list(map(int,input().split())))
    for p in range(t):
        star1 = (start[0]-circle[p][0])**2+(start[1]-circle[p][1])**2 < circle[p][2]**2
        star2 = (start[2]-circle[p][0])**2+(start[3]-circle[p][1])**2 < circle[p][2]**2
        if star1 and star2:
            pass
        else:
            if star1 or star2:
                result += 1
    print(result)
