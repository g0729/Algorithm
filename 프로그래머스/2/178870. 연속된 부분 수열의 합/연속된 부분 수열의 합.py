from collections import deque
def solution(sequence, k):
    answer = []
    now_sum=0
    arr=deque()
    for idx, num in enumerate(sequence):
        arr.append([num,idx])
        now_sum+=num
        
        if now_sum<k:
            continue
        if now_sum>k:
            while now_sum>k:
                now_sum-=arr.popleft()[0]
        if now_sum==k:
            if not answer:
                answer=list(arr)
            else:
                if len(arr)<len(answer):
                    answer=list(arr)
    return [answer[0][1],answer[-1][1]] if len(answer) !=1 else [answer[0][1],answer[0][1]]