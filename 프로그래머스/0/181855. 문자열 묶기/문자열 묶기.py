from collections import Counter
def solution(strArr):
    c=Counter(map(len,strArr))
    return c.most_common(1)[0][1]