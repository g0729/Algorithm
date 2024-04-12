def solution(n, control):
    ma={'w':1,'s':-1,'d':10,'a':-10}
    for c in control:
        n+=ma[c]
    return n