def solution(my_string, indices):
    return ''.join(c for idx,c in enumerate(my_string) if idx not in indices)