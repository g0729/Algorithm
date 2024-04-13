def solution(l, r):
    answer = []
    for i in range(l,r+1):
        num=str(i)
        flag=True
        for c in num:
            if c!='5' and c!='0':
                flag=False
                break
        if flag:
            answer.append(i)
    
    return answer if answer else [-1]