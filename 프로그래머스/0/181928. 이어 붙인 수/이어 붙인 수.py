def solution(num_list):
    return int(''.join(str(c) for c in num_list if c%2==1))+int(''.join(str(c)for c in num_list if c%2==0))