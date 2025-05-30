s = list(input())
st = []

for c in s:
    if c.isdigit():
        st.append(c)
    else:
        a, b = st.pop(), st.pop()
        st.append(int(eval(f"{b} {c} {a}")))

print(st[0])
