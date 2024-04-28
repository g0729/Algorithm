from collections import deque

def solution(queue1, queue2):
    sum1,sum2=sum(queue1),sum(queue2)
    queue1,queue2=deque(queue1),deque(queue2)
    
    Sum=(sum1+sum2)//2
    
    answer=0
    
    while sum1!=Sum:
        if answer>300000:
            return -1
        if sum1>Sum:
            a=queue1.popleft()
            sum1-=a
            sum2+=a
            queue2.append(a)
        elif sum2>Sum:
            a=queue2.popleft()
            sum2-=a
            sum1+=a
            queue1.append(a)
        answer+=1
    return answer
    