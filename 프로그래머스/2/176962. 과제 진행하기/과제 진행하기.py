
def solution(plans):
    answer = []
    plans.sort(key=lambda x: x[1])
    
    def convert(time):
        return int(time[:2])*60+int(time[3:])
    
    st=[[plans[0][0],int(plans[0][2])]]
    
    for i in range(1,len(plans)):
        time=convert(plans[i][1])-convert(plans[i-1][1])
        
        if st:
            while st and st[-1][1]<=time:
                time-=st[-1][1]
                answer.append(st[-1][0])
                st.pop()
                
            if st:
                st[-1][1]-=time
        st.append([plans[i][0],int(plans[i][2])])
    while st:
        answer.append(st[-1][0])
        st.pop()
    return answer