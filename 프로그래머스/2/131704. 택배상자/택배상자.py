def solution(order):
    answer = 0
    idx=1
    st=[]
    for a in order:
        if a==idx:
            answer+=1
            idx+=1
        else:
            if st and st[-1]==a:
                st.pop()
                answer+=1
            else:
                if idx>a:
                    return answer
                while idx!=a:
                    st.append(idx)
                    idx+=1
                idx+=1
                answer+=1
    return answer