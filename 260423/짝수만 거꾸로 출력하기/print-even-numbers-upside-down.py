n=int(input())
res= [a for a in map(int,input().split()) if a%2==0]
print(" ".join(map(str,res[::-1])))