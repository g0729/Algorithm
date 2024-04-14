def solution(lines):
    line = [0]*202
    for a,b in lines:
        for i in range(a,b):
            line[i+100]+=1
    res=0
    for i in range(201):
        if line[i]>=2:
            res+=1
    return res