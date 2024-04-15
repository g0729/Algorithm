def solution(my_string):
    se=set()
    answer=''
    for c in my_string:
        if c not in se:
            answer+=c
            se.add(c)
    return answer