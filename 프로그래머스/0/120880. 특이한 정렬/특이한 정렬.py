def solution(numlist, n):
    temp=[[abs(a-n),a] for a in numlist]
    temp.sort(key=lambda x:(x[0],-x[1]))
    return [temp[i][1] for i in range(len(temp))]