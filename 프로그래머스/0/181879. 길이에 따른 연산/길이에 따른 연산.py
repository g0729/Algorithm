def solution(num_list):
    if len(num_list)>=11:
        return sum(num_list)
    else:
        a=1
        for b in num_list:
            a *=b
        return a