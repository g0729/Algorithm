def solution(n):
    answer = []
    now=2
    while n!=1:
        if n%now==0:
            answer.append(now)
            while n%now==0:
                n//=now
        now+=1
    return answer