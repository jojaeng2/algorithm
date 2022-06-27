from collections import deque
s = list(map(str,input()))
t = deque(list(map(str,input())))
state = True
while len(s) < len(t):
    
    if state == True:
        if t[-1] == "B":
            t.pop()
            state = False
        else:
            t.pop()
    else:
        if t[0] == "B":
            t.popleft()
            state = True
        else:
            t.popleft()

t = list(t)
if state == False:
    t.reverse()
if s == t:
    print(1)
else:
    print(0)