def time_change(time):
    hour,minute=int(time[0:2]),int(time[3:5])
    return hour*60+minute

def solution(book_time):
    answer = 0
    cnt=[0]*(60*24+1)
    for times in book_time:
        start=time_change(times[0])
        end=min(60*24,time_change(times[1])+10)
        for i in range(start,end):
            cnt[i]+=1
    return max(cnt)