from collections import Counter
def solution(s):
    c=Counter(s)
    return ''.join(sorted([a for a in c if c[a]==1]))