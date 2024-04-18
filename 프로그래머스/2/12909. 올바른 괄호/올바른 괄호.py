def solution(s):
    a=0
    for c in s:
        a += 1 if c=='(' else -1
        if a<0:
            return False
        
    return a==0