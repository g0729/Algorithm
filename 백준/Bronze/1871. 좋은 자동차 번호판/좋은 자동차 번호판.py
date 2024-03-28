for _ in range(int(input())):
    a,b=input().split('-')
    b=int(b)
    temp=0
    for i in range(3):
        temp+=(ord(a[i])-65)*(26**(2-i))
    if abs(temp-b)<=100:
        print('nice')
    else:
        print('not nice')