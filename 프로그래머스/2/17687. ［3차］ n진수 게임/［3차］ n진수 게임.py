def solution(n, t, m, p):
    answer = ''
    s='0'
    digits=["0","1","2","3","4","5","6","7","8","9","A","B","C","D","E","F"]
    def f(num):
        res=''
        while num:
            num,mod=divmod(num,n)
            res+=digits[mod]
        return res[::-1]
    
    for i in range(100000):
        s+=f(i)    
    for i in range(t):
        answer+=s[p+i*m-1]
    
    return answer