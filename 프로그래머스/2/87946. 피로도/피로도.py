from itertools import permutations

def solution(k, dungeons):
    answer = -1
    for arr in permutations(range(len(dungeons))):
        temp=k
        cnt=0
        for a in arr:
            if dungeons[a][0]>temp:
                break
            else:
                temp-=dungeons[a][1]
                cnt+=1
        answer=max(cnt,answer)
    return answer