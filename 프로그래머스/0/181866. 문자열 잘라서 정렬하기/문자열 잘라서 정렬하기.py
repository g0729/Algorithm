def solution(myString):
    return sorted( c for c in myString.split('x') if len(c)!=0)