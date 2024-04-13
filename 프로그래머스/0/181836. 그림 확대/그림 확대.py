def solution(picture, k):
    answer=[]
    for s in picture:
        temp=''
        for c in s:
            temp+=c*k
        for _ in range(k):
            answer.append(temp)
            
    return answer
    