def solution(babbling):
    answer = 0
    words=['aya','ye','woo','ma']
    
    for s in babbling:
        for word in words:
            s=s.replace(word,' ',1)
        flag=True
        for c in s:
            if c!=' ':
                flag=False
        if flag:
            answer+=1
    return answer