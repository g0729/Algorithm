def solution(n, m, section):
    answer = 0
    
    a=0
    
    for i in section:
        if i >a:
            a=i+m-1
            answer+=1
        
    return answer