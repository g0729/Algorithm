def solution(targets):
    answer = 0
    targets.sort(key=lambda x: (x[1],x[0]))
    
    now=-1
    for i in range(len(targets)):
        if targets[i][0]>=now:
            now=targets[i][1]
            answer+=1
        
    return answer