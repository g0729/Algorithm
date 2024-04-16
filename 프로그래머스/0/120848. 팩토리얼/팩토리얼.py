def solution(n):
    answer = 1
    now =1
    while now<=n:
        now*=answer
        answer+=1
        
    return answer-2