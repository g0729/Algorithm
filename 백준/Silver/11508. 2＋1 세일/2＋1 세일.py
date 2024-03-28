n=int(input())
arr=[int(input()) for _ in range(n)]
res=0

arr.sort(reverse=True)

for i in range(len(arr)):
    if i%3==2:
        continue
    res+=arr[i]

print(res)