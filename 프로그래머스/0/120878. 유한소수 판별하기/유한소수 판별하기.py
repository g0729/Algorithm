def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)
def divide(num,target):
    while(num%target==0):
        num//=target
    return num

def solution(a, b):
    c=gcd(a,b)
    b//=c
    b=divide(b,2)
    b=divide(b,5)
    
    return 1 if b==1 else 2
