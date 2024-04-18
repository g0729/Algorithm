def solution(numbers):
    answer = []
    for n in numbers:
        if n%2==0:
            answer.append(n+1)
        else:
            idx=-1
            temp=n
            while temp&1==1:
                temp>>=1
                idx+=1
            temp=2**idx
            answer.append(n+temp)
    return answer