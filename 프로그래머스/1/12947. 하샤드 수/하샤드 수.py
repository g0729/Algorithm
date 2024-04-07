def solution(x):
    answer = True
    s=str(x)
    temp=0
    for c in s:
        temp+=int(c)
    
    return x%temp==0