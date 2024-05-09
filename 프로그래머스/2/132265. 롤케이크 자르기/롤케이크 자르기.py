def solution(topping):
    answer = 0
    window_left,window_right=[0]*(10001),[0]*(10001)
    left,right=0,0
    for a in topping:
        if window_right[a]==0:
            right+=1
        window_right[a]+=1
    
    for a in topping:
        if window_left[a]==0:
            left+=1
        window_left[a]+=1
        if window_right[a]==1:
            right-=1
        window_right[a]-=1
        if left==right:
            answer+=1
    return answer