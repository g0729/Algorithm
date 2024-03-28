import math
import sys

def isPrime(n):
    if n==1:
        return False
    for i in range(2,int(math.sqrt(n))+1):
        if n %i==0:
            return False
    return True

n,k=map(int,input().split())

for i in range(1,k):
    if isPrime(i):
        if n%i==0:
            print("BAD",i)
            sys.exit()

print("GOOD")