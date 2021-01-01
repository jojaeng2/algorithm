n = int(input())
result = 0
n = 1000-n
while n != 0:
    if n // 500 >= 1:
        result += n//500
        n %= 500
    elif n//100 >= 1:
        result += n//100
        n %= 100
    elif n//50 >= 1:
        result += n//50
        n %= 50
    elif n//10 >= 1:
        result += n//10
        n %= 10
    elif n//5 >= 1:
        result += n//5
        n %= 5
    else:
        result += n//1
        n %= 1
print(result)
