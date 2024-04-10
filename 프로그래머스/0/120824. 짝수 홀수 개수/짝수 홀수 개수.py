def solution(num_list):
    cnt=0
    for a in num_list:
        if a%2:
            cnt+=1
    return [len(num_list)-cnt,cnt]
    