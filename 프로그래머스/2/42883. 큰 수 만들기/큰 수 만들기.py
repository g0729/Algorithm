def solution(number, k):
    st = []

    for num in number:
        if not st:
            st.append(num)
        else:
            if st[-1] < num:
                while st and st[-1] < num and k:
                    st.pop()
                    k -= 1
                st.append(num)
            else:
                st.append(num)
    while k:
        st.pop()
        k-=1
    return "".join(st)
