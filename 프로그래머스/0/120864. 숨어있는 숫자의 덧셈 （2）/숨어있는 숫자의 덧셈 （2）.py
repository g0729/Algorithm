import re
def solution(my_string):
    my_string=re.sub(r'[a-zA-Z]',' ',my_string)
    return sum(int(c) for c in my_string.split())