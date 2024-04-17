def solution(s):
    answer=[ int(c) for c in s.split()]
    return ' '.join([str(min(answer)),str(max(answer))])