w = list(map(str,input()))
for i in range(len(w)):
    if i == 0:
        print(w[i],end="")
    elif i % 10 == 9:
        print(w[i],end="\n")
    else:
        print(w[i],end="")
