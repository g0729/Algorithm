def solution(n, stations, w):
    answer = 0

    start=1
    for a in stations:
        left,right=max(a-w,1),min(a+w,n)
        if start<left:
            diff=left-start
            answer+=(diff+2*w)//(2*w+1)
        start=right+1
    answer+=((n-start+1)+2*w)//(2*w+1)
    return answer