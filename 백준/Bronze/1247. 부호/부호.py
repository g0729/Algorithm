from sys import stdin
for _ in range(3):
    n=int(input())
    sum=0
    for i in range(n):
        temp=int(stdin.readline())
        sum+=temp
    
    if sum == 0:
        print(0)
    elif sum < 0:
        print('-')
    elif sum >0:
        print('+')