a,b=map(int,input().split())

print(a,b,end=' ')

for i in range(8):
    a,b=b,(a+b)%10

    print(b,end=' ')