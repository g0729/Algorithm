def solution(left, right):
    answer=(left+right)*(right-left+1)//2
    now=1
    while(now*now<=right):
        if(now*now>=left):
            answer-=now*now*2
        now+=1
    
    
    return answer