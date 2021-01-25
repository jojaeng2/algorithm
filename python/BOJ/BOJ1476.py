a,b,c = map(int,input().split())
result = 1
year = [1,1,1]
while year[0] != a or year[1] != b or year[2] != c:
    year[0] += 1
    year[1] += 1
    year[2] += 1
    result += 1
    if year[0] == 16:
        year[0] = 1
    if year[1] == 29:
        year[1] = 1
    if year[2] == 20:
        year[2] = 1
print(result)
print(a)
