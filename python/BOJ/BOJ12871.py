s = input()
t = input()
for i in range(min(len(s),len(t)),(len(s)*len(t))+1):
    if i % len(s) == 0 and i % len(t) == 0:
        mi = i

s *= (mi//len(s))
t *= (mi//len(t))
result = True
print(s)
print(t)
for i in range(mi):
    if s[i] != t[i]:
        result = False
        break
if result == False:
    print(0)
else:
    print(1)  