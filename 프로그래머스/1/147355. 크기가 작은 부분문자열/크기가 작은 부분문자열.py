def solution(t, p):
    answer = 0
    a=len(p)
    for i in range(len(t)-a+1):
        if int(t[i:i+a])<=int(p):
            answer+=1
    return answer