def solution(food):
    answer = ''
    
    for idx,i in enumerate(food[1:]):
        answer+=str(idx+1)*(i//2)
    answer=answer+'0'+answer[::-1]
    return answer