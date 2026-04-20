a,b=input().split()

if len(a) == len(b):
    print("same")
    exit(0)
if len(a) < len(b):
    a,b=b,a

print(a,len(a))
