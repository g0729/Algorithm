def gcd(a,b):
    if b==0:
        return a
    else:
        return gcd(b,a%b)

def solution(numer1, denom1, numer2, denom2):
    d=denom1*denom2//gcd(denom1,denom2)
    n=numer1*(d//denom1)+numer2*(d//denom2)
    a=gcd(d,n)
    return [n//a,d//a]