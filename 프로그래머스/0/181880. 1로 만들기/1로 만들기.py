def solution(num_list):
    answer=0
    
    for num in num_list:
        cnt =0
        while(num!=1):
            num = (num-1)//2 if num%2 else num//2
            cnt+=1
        answer+=cnt
    return answer