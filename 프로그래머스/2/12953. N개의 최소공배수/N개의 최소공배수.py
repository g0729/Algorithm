def gcd(a,b):
    if b==0:
        return a
    return gcd(b,a%b)
def solution(arr):
    mod,answer=arr[0],arr[0]
    for i in range(1,len(arr)):
        mod=gcd(answer,arr[i])
        answer=answer*arr[i]//mod
    return answer