def solution(n, arr1, arr2):
    answer = []
    temp1,temp2=[],[]
    for a in arr1:
        temp3=[]
        a=bin(a)[2:]
        a="0"*(n-len(a))+a
        temp1.append(["#" if c=='1' else ' ' for c in a])
    for a in arr2:
        temp3=[]
        a=bin(a)[2:]
        a="0"*(n-len(a))+a
        temp2.append(["#" if c=='1' else ' ' for c in a])
    
    for i in range(len(temp1)):
        answer.append(''.join(' ' if temp1[i][j]==' ' and temp2[i][j]==' ' else '#' for j in range(len(temp1[i]))))
    return answer