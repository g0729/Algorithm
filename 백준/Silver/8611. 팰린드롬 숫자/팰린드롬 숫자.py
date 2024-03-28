def cal(n,b):
    res=[]
    while 1:
        if n//b ==0:
            res.append(n)
            break
        res.append(n%b)
        n=n//b
    res.reverse()
    return "".join(map(str,res))

n=int(input())

flag=False
for i in range(2,11):
    temp=cal(n,i)
    if temp==temp[::-1]:
        flag=True
        print(i,temp)

if flag==False:
    print("NIE")
