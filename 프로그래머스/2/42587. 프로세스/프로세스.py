from collections import deque

def solution(priorities, location):
    answer = 0
    
    q=[[a,idx] for idx , a in enumerate(priorities)]
    q=deque(q)
    max_value=max(q,key=lambda x: x[0])[0]
    idx=1
    while True:
        if q[0][0]!=max_value:
            q.append(q.popleft())
        else:
            if q.popleft()[1]==location:
                return idx
            idx+=1
            max_value=max(q,key=lambda x: x[0])[0]