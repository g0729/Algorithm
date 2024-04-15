def solution(order):
    a=list(str(order))
    return a.count('3')+a.count('6')+a.count('9')