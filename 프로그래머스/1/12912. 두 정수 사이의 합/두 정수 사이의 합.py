def solution(a, b):
    if a>b:
        c=a
        a=b
        b=c
    return (a+b)*(b-a+1)//2