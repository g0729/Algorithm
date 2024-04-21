def solution(s):
    s=s.lower()
    s=list(s)
    flag=True
    for i in range(len(s)):
        if flag and s[i] !=' ':
            if s[i].isalpha():
                s[i]=s[i].upper()
            flag=False
        elif s[i]==' ':
            flag=True
    return ''.join(s)