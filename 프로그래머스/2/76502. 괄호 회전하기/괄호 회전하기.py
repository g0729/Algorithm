def check(temp):
    st=[]
    
    for c in temp:
        if c==']':
            if not st or st[-1]!='[':
                return False
            else:
                st.pop()
        elif c==r')':
            if not st or st[-1]!=r'(':
                return False
            else:
                st.pop()
        elif c==r'}':
            if not st or st[-1]!=r'{':
                return False
            else:
                st.pop()
        else:
            st.append(c)
    return False if st else True
def solution(s):
    answer =0
    for i in range(len(s)):
        temp=s[i:]+s[:i]
        if check(temp):
            answer+=1
        
    return answer