def solution(n):
    temp=''
    while n>0:
        n,mod=divmod(n,3)
        temp+=str(mod)
    
    return int(temp,3)