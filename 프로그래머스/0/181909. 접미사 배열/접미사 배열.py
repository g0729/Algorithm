def solution(my_string):
    return sorted([my_string[idx:] for idx in range(len(my_string))])