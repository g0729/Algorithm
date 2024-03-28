N,L = map(int,input().split())

A=[0]+ list(map(int,input().split()))

alchol_in_blood=0
cnt=0
for i in range(1,L+1):
    alchol_in_blood+=A[i]
    if(129<=alchol_in_blood and alchol_in_blood<=138):
        cnt+=1

for i in range(1,N-L+2):
    if i == N-L+1:
        break
    alchol_in_blood -=A[i]
    alchol_in_blood +=A[L+i]
    if(129<=alchol_in_blood and alchol_in_blood<=138):
        cnt+=1

print(cnt)