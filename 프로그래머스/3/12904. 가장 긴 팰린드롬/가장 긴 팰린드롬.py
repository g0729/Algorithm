def solution(s):

    for length in range(len(s)+1,-1,-1):
        for start in range(0,len(s)-length):
            temp=s[start:start+length+1]
            if temp==temp[::-1]:
                return length+1
    
    