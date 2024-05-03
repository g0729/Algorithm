def hanoi(n,From,Temp,To):
    if n==1:
        global answer
        answer.append([From,To])
        return
    hanoi(n-1,From,To,Temp)
    answer.append([From,To])
    hanoi(n-1,Temp,From,To)
def solution(n):
    global answer
    answer = []
    hanoi(n,1,2,3)
    return answer