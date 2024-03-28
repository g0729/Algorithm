def update(start,end,node,idx):
    if idx<start or idx>end:
        return SumTree[node]
    
    SumTree[node]+=a
    NumTree[node]+=1
    if start==end:
        return 
    mid=(start+end)//2
    
    update(start,mid,2*node,idx)
    update(mid+1,end,2*node+1,idx)

def Sum(start,end,node,left,right):
    if right<start or left>end:
        return 0
    if left<=start and end<=right:
        return SumTree[node]
    mid=(start+end)//2
    return Sum(start,mid,2*node,left,right)+Sum(mid+1,end,2*node+1,left,right)

def NumSum(start,end,node,left,right):
    if right<start or left>end:
        return 0
    if left<=start and end<=right:
        return NumTree[node]
    mid=(start+end)//2
    return NumSum(start,mid,2*node,left,right)+NumSum(mid+1,end,2*node+1,left,right)

MAX=200000
MOD=1000000007
n=int(input())
SumTree=[0]*(4*(MAX+1))
NumTree=[0]*(4*(MAX+1))
res=1
for i in range(n):
    a=int(input())
    update(0,MAX,1,a)
    rightSum=Sum(0,MAX,1,a+1,MAX)
    rightNum=NumSum(0,MAX,1,a+1,MAX)
    leftSum=Sum(0,MAX,1,0,a-1)
    leftNum=NumSum(0,MAX,1,0,a-1)
    if i==0:
        continue
    res*=(rightSum-a*rightNum)+(a*leftNum-leftSum)
    res%=MOD

print(res)
