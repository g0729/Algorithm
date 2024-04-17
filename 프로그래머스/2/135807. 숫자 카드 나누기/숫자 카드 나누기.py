def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)

def solution(arrayA, arrayB):
    answer = 0
    gcd1,gcd2=arrayA[0],arrayB[0]
    
    for i in range(1,len(arrayA)):
        gcd1=gcd(gcd1,arrayA[i])
    for i in range(1,len(arrayA)):
        gcd2=gcd(gcd2,arrayB[i])
    list_1,list_2=[],[]
    for i in range(1,int(gcd1**0.5)+1):
        if i*i==gcd1:
            list_1.append(i)
        elif gcd1%i==0:
            list_1.append(i)
            list_1.append(gcd1//i)
    for i in range(1,int(gcd2**0.5)+1):
        if i*i==gcd2:
            list_2.append(i)
        elif gcd2%i==0:
            list_2.append(i)
            list_2.append(gcd2//i)
    list_1.sort(reverse=True)
    list_2.sort(reverse=True)
    
    for a in list_1:
        flag=True
        for b in arrayB:
            if b%a==0:
                flag=False
                break
        if flag:
            answer=a
            break
    
    for a in list_2:
        flag=True
        for b in arrayA:
            if b%a==0:
                flag=False
                break
        if flag:
            answer=max(answer,a)
            break
    return answer