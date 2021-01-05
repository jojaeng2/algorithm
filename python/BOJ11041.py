import sys
number = 1000000007
N,K = map(int,sys.stdin.readline().split())
def div(a,b):
    if b != 1:
        result = div(a,b//2)
        if b%2 == 0:
            return result **2 %number
        else:
            return result **2*a%number
    else:
        return a%number
n = 1
k = 1
for i in range(1,N+1): # n!
    n *= i
    n %= number
for i in range(1,K+1):﻿ #k!
    k *= i
    k %= number
for i in range(1,N-K+1): #﻿ k!(n-k)!
    k *= i
    k %= number

print(n*div(k,number-2)%number)
