import math
def cal(r1,r2):
    answer=0
    for i in range(1,r1):
        answer+=int((r2**2-i**2)**0.5)-math.ceil((r1**2-i**2)**0.5)+1
    for i in range(r1,r2):
        answer+=int((r2**2-i**2)**0.5)
    return answer*4+(r2-r1+1)*4
def solution(r1, r2):
    return cal(r1,r2)