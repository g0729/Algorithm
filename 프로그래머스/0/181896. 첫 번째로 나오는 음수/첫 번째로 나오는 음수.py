def solution(num_list):
    for idx, a in enumerate(num_list):
        if a<0:
            return idx
    return -1