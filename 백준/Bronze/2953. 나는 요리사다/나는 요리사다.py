maxIdx=0
maxSum=0

for i in range(5):
    tempSum=sum((list(map(int,input().split()))))
    if tempSum>maxSum: 
        maxSum=tempSum
        maxIdx=i+1

print(maxIdx,maxSum)