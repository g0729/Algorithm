def solution(arr, k):
    se=set()
    answer=[]
    for a in arr:
        if a not in se:
            se.add(a)
            answer.append(a)
    
    
    if len(answer)>=k:
        return answer[:k]
    else:
        return answer+[-1]*(k-len(answer))