def solution(arr):
    answer=[]
    for a in arr:
        if len(answer)==0:
            answer.append(a)
        else:
            if answer[-1]==a:
                answer.pop()
            else:
                answer.append(a)
    return answer if len(answer) else [-1]
    