def solution(n):
    answer = 1
    for i in range(2,n+1):
        temp = i*(i+1)//2
        if temp>n:
            break
        left=n-temp
        if left%i==0:
            answer+=1
    return answer