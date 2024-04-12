def solution(my_strings, parts):
    return ''.join(a[b[0]:b[1]+1]for a,b in zip(my_strings,parts))