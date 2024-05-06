from itertools import permutations
from math import sqrt
def isPrime(num):
    if num<=1:
        return False
    for i in range(2,int(sqrt(num))+1):
        if num%i==0:
            return False
    return True

def solution(numbers):
    answer = 0
    n=len(numbers)
    numbers=list(numbers)
    se=set()
    for i in range(1,n+1):
        for order in permutations(range(n),i):
            num=int(''.join(numbers[a] for a in order))
            
            if num in se:
                continue
            if isPrime(num):
                answer+=1
                se.add(num)
    return answer