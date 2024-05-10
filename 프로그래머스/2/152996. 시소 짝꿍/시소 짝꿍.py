from collections import defaultdict
from math import comb
def solution(weights):
    answer = 0
    dic=defaultdict(int)
    
    for weight in weights:
        dic[weight]+=1
        
    arr=list(dic.items())
    arr.sort(key=lambda x:x[0])
    
    for i in range(len(arr)):
        if arr[i][1]>=2:
            answer+=comb(arr[i][1],2)
        for j in range(2,5):
            for k in range(2,j):
                left=arr[i][0]*j
                if left%k==0:
                    answer+=dic[left//k]*arr[i][1]
    return answer