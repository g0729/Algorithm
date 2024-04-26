def isPrime(num):
    if num==1:
        return False
    for i in range(2,int(num**0.5)+1):
        if num%i==0:
            return False
    return True

def solution(n, k):
    answer =0
    s=''
    while n:
        n,mod=divmod(n,k)
        s+=str(mod)
    s=s[::-1]
    for a in s.split('0'):
        if len(a)==0:
            continue
        if isPrime(int(a)):
            answer+=1
        
    return answer