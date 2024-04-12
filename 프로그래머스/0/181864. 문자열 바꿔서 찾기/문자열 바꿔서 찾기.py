def solution(myString, pat):
    temp=''
    for c in myString:
        if c=='A':
            temp+='B'
        else:
            temp+='A'
    
    return 1 if pat in temp else 0