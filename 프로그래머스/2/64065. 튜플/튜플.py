import re
def solution(s):
    answer = []
    s = s[1:-1]

    c = re.findall(r"\{([^}]+)", s)
    c.sort(key=lambda x : len(x))
    c=[c[i].split(',') for i in range(len(c))]
    
    answer.append(int(c[0][0]))
    se=set(c[0])
    for i in range(1,len(c)):
        for j in range(len(c[i])):
            if c[i][j] not in se:
                answer.append(int(c[i][j]))
                se.add(c[i][j])
    return answer