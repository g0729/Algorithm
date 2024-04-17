
def solution(arr):
    answer=1
    while True:
        flag=True
        for a in arr:
            if answer % a!=0:
                flag=False
                break
        if flag:
            return answer
        answer+=1