def solution(n):
    answer = ''
    while n:
        mod=(n-1)%3
        n=(n-1)//3
        if mod==0:
            answer+='1'
        elif mod==1:
            answer+='2'
        else:
            answer+='4'
    return answer[::-1]