def solution(array):
    count=[0]*1001
    
    for a in array:
        count[a]+=1
    max_val=max(count)
    answer=-1
    for i in range(len(count)):
        if count[i]==max_val:
            if answer==-1:
                answer=i
            else:
                return -1
    return answer