def solution(d, budget):
    sum=0
    d.sort()
    for i in range(len(d)):
        sum+=d[i]
        if budget<sum:
            return i
    
    return len(d)