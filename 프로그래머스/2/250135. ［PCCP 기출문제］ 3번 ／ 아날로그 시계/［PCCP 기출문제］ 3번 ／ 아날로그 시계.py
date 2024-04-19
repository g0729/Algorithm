def cal(time):
    return int(time*59/3600)+int(time*719/43200) -(2 if time>=43200 else 1)

def solution(h1, m1, s1, h2, m2, s2):
    time1=h1*3600+m1*60+s1
    time2=h2*3600+m2*60+s2
    print(time1,time2)
    print(cal(time1),cal(time2))
    return cal(time2)-cal(time1) + (1 if (time1*59)%3600==0 or (time1%719)%43200 ==0 else 0)