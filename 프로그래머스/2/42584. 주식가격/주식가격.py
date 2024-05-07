def solution(prices):
    answer = [0]*len(prices)
    st=[]
    for idx , price in enumerate(prices):
        while st and price<st[-1][0]:
            answer[st[-1][1]]=idx-st[-1][1]
            st.pop()
        st.append([price,idx])
    while st:
        answer[st[-1][1]]=idx-st[-1][1]
        st.pop()
    return answer